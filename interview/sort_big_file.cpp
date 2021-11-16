/*20211026
大文件排序
key value
key 64bytes
value 最多 32bytes
按照key排序，key相同按照value排序，key和value都相同只取一次
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// 1. 分割文件，按照大小分割，注意处理行，不能拆分行

// 2. 排序子文件

struct KV {
  int64_t key;
  std::string value;

  bool operator==(const KV& o) { return key == o.key && value == o.value; }
  bool operator<(const KV& o) {
    return key < o.key || (key == o.key && value < o.value);
  }
};

void sort_file(const std::string& path, const std::string& out_path) {
  std::ifstream reader(path);
  std::vector<KV> kvs;
  int64_t key;
  std::string value;
  while (!reader.eof()) {
    reader >> key >> value;
    kvs.emplace_back({key, value});
  }
  reader.close();
  std::sort(kvs.begin(), kvs.end());
  // auto last = std::unique(kvs.begin(), kvs.end());
  // output
  std::ofstream writer(out_path);
  for (auto iter = kvs.begin(); iter != kvs.end(); ++iter) {
    writer << iter->key << " " << iter->value;
  }
  writer.close();
}

// 3. 合并多个子文件
const size_t buffer_size = 8 * 1024;

struct Buff {
  KV* data;
  size_t pos;

  Buff() : pos(0) { data = new KV[buffer_size]; }
  ~Buff() {
    if (data) {
      delete[] data;
      data = nullptr;
    }
  }
};

void read_files_to_buffers(std::vector<std::ifstream>& readers,
                           std::vector<Buff>& buffs) {
  for (size_t i = 0; i < readers.size(); ++i) {
    if (buffs[i].pos < buffer_size) continue;
    size_t index = 0;
    while (!readers[i].eof() && index < buffer_size) {
      readers[i] >> buffs[i].data->key >> buffs[i].data->value;
      ++index;
    }
    buffs[i].pos = 0;
  }
}

void combine(const std::vector<std::string>& files,
             const std::string& out_path) {
  if (files.empty()) return;
  std::vector<std::ifstream> readers(files.size());
  for (size_t i = 0; i < files.size(); ++i) {
    readers[i].open(files[i]);
  }
  std::vector<Buff> read_buffers(files.size());
  std::ofstream writer(out_path);
  Buff write_buffer;
  KV* last = nullptr;

  while (true) {
    read_files_to_buffers(readers, read_buffers);
    KV* min = nullptr;
    size_t index = 0;
    for (size_t i = 1; i < files.size(); ++i) {
      if (read_buffers[i].pos < buffer_size &&
          (min == nullptr ||
           read_buffers[i].data[read_buffers[i].pos] < *min)) {
        min = &read_buffers[i].data[read_buffers[i].pos];
        index = i;
      }
    }
    if (min == nullptr) {
      break;
    }
    ++read_buffers[index].pos;
    if (last == nullptr || *last == *min) {
      last = min;
    } else {
      write_buffer.data[write_buffer.pos].key = min->key;
      write_buffer.data[write_buffer.pos].value = min->value;
      ++write_buffer.pos;
      if (write_buffer.pos >= buffer_size) {
        for (size_t i = 0; i < buffer_size; ++i) {
          writer << write_buffer.data[i].key << " "
                 << write_buffer.data[i].value;
        }
        write_buffer.pos = 0;
      }
      last = min;
    }
  }
  for (size_t i = 0; i < readers.size(); ++i) {
    readers[i].close();
  }
  writer.close();
}
