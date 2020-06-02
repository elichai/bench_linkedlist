#include <benchmark/benchmark.h>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <iterator>
#include <list>
#include <numeric>

using std::size_t;
using std::uint8_t;

constexpr static size_t ITERS = 2048;

static void BM_InsertBackList(benchmark::State &state) {
  for (auto _ : state) {
    std::list<uint8_t> list;
    for (size_t i = 0; i < ITERS; i++) {
      list.emplace_back(1);
    }
    benchmark::DoNotOptimize(list);
  }
}

static void BM_InsertBackDeque(benchmark::State &state) {
  for (auto _ : state) {
    std::deque<uint8_t> deque;
    for (size_t i = 0; i < ITERS; i++) {
      deque.emplace_back(1);
    }
    benchmark::DoNotOptimize(deque);
  }
}

static void BM_InsertFrontList(benchmark::State &state) {
  for (auto _ : state) {
    std::list<uint8_t> list;
    for (size_t i = 0; i < ITERS; i++) {
      list.emplace_front(1);
    }
    benchmark::DoNotOptimize(list);
  }
}

static void BM_InsertFrontDeque(benchmark::State &state) {
  for (auto _ : state) {
    std::deque<uint8_t> deque;
    for (size_t i = 0; i < ITERS; i++) {
      deque.emplace_front(1);
    }
    benchmark::DoNotOptimize(deque);
  }
}

static void BM_SumList(benchmark::State &state) {
  std::list<uint8_t> list;
  for (size_t i = 0; i < ITERS; i++) {
    list.emplace_back(1);
  }

  for (auto _ : state) {
    size_t sum = std::accumulate(list.cbegin(), list.cend(), size_t(0));
    benchmark::DoNotOptimize(sum);
  }
}

static void BM_SumDeque(benchmark::State &state) {
  std::deque<uint8_t> deque;
  for (size_t i = 0; i < ITERS; i++) {
    deque.emplace_back(1);
  }

  for (auto _ : state) {
    size_t sum = std::accumulate(deque.cbegin(), deque.cend(), size_t(0));
    benchmark::DoNotOptimize(sum);
  }
}

static void BM_InsertRemoveList(benchmark::State &state) {
  for (auto _ : state) {
    std::list<uint8_t> list;
    for (size_t i = 0; i < ITERS; i++) {
      list.emplace_back(1);
    }
    for (size_t i = 0; i < ITERS; i++) {
      benchmark::DoNotOptimize(list.back());
      list.pop_back();
    }
    benchmark::DoNotOptimize(list);
  }
}

static void BM_InsertRemoveDeque(benchmark::State &state) {
  for (auto _ : state) {
    std::deque<uint8_t> deque;
    for (size_t i = 0; i < ITERS; i++) {
      deque.emplace_back(1);
    }
    for (size_t i = 0; i < ITERS; i++) {
      benchmark::DoNotOptimize(deque.back());
      deque.pop_back();
    }
    benchmark::DoNotOptimize(deque);
  }
}

static void BM_SplitAppendList(benchmark::State &state) {
  std::list<uint8_t> list;
  for (size_t i = 0; i < ITERS; i++) {
    list.emplace_back(1);
  }

  for (auto _ : state) {
    for (size_t i = 0; i < ITERS / 64; i++) {
      std::list<uint8_t> new_list;
      auto it = list.begin();
      std::advance(it, ITERS / 2);
      // Split the list in half.
      new_list.splice(new_list.begin(), list, it, list.end());
      // Merge the list back.
      list.splice(list.end(), new_list);
      benchmark::DoNotOptimize(list.begin());
    }
  }
}

static void BM_SplitAppendDeque(benchmark::State &state) {
  std::deque<uint8_t> deque;
  for (size_t i = 0; i < ITERS; i++) {
    deque.emplace_back(i);
  }

  for (auto _ : state) {
    for (size_t i = 0; i < ITERS / 64; i++) {
      // Copy the last ITERS / 2 elements.
      auto it = deque.begin();
      std::advance(it, ITERS / 2);
      std::deque<uint8_t> new_deque(it, deque.end());
      // Delete last ITERS / 2 from deque
      deque.erase(it, deque.end());
      // Merge the deque bact.
      deque.insert(deque.end(), new_deque.begin(), new_deque.end());
      benchmark::DoNotOptimize(deque.begin());
    }
  }
}

// Register the function as a benchmark
BENCHMARK(BM_InsertBackList);
BENCHMARK(BM_InsertBackDeque);
BENCHMARK(BM_InsertFrontList);
BENCHMARK(BM_InsertFrontDeque);
BENCHMARK(BM_SumList);
BENCHMARK(BM_SumDeque);
BENCHMARK(BM_InsertRemoveList);
BENCHMARK(BM_InsertRemoveDeque);
BENCHMARK(BM_SplitAppendList);
BENCHMARK(BM_SplitAppendDeque);
// Run the benchmark
BENCHMARK_MAIN();