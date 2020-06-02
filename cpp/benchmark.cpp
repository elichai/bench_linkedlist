#include <benchmark/benchmark.h>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <iostream>
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

// Register the function as a benchmark
BENCHMARK(BM_InsertBackList);
BENCHMARK(BM_InsertBackDeque);
BENCHMARK(BM_InsertFrontList);
BENCHMARK(BM_InsertFrontDeque);
BENCHMARK(BM_SumList);
BENCHMARK(BM_SumDeque);
BENCHMARK(BM_InsertRemoveList);
BENCHMARK(BM_InsertRemoveDeque);
// Run the benchmark
BENCHMARK_MAIN();