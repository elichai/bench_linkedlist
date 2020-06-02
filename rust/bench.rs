use criterion::{black_box, criterion_group, criterion_main, BenchmarkId, Criterion};
use std::collections::{LinkedList, VecDeque};

const ITERS: usize = 2048;

fn bench_insert_back(b: &mut Criterion) {
    let mut group = b.benchmark_group("Insert Back");
    group.bench_function(BenchmarkId::new("List", ""), |b| {
        b.iter(|| {
            let mut list = LinkedList::new();
            for _ in 0..ITERS {
                list.push_back(1u8);
            }
            black_box(list);
        })
    });
    group.bench_function(BenchmarkId::new("Deque", ""), |b| {
        b.iter(|| {
            let mut deque = VecDeque::new();
            for _ in 0..ITERS {
                deque.push_back(1u8);
            }
            black_box(deque);
        })
    });
}

fn bench_insert_front(b: &mut Criterion) {
    let mut group = b.benchmark_group("Insert Front");
    group.bench_function(BenchmarkId::new("List", ""), |b| {
        b.iter(|| {
            let mut list = LinkedList::new();
            for _ in 0..ITERS {
                list.push_front(1u8);
            }
            black_box(list);
        })
    });
    group.bench_function(BenchmarkId::new("Deque", ""), |b| {
        b.iter(|| {
            let mut deque = VecDeque::new();
            for _ in 0..ITERS {
                deque.push_front(1u8);
            }
            black_box(deque);
        })
    });
}

fn bench_sum(b: &mut Criterion) {
    let mut group = b.benchmark_group("Sum");
    let mut list = LinkedList::new();
    for _ in 0..ITERS {
        list.push_back(1u8);
    }
    group.bench_function(BenchmarkId::new("List", ""), |b| {
        b.iter(|| {
            let sum: usize = list.iter().map(|a| *a as usize).sum();
            black_box(sum);
            black_box(&mut list);
        })
    });

    let mut deque = VecDeque::from(vec![1u8; ITERS]);
    group.bench_function(BenchmarkId::new("Deque", ""), |b| {
        b.iter(|| {
            let sum: usize = deque.iter().map(|a| *a as usize).sum();
            black_box(sum);
            black_box(&mut deque);
        })
    });
}

fn bench_insert_remove(b: &mut Criterion) {
    let mut group = b.benchmark_group("Insert & Remove");
    group.bench_function(BenchmarkId::new("List", ""), |b| {
        b.iter(|| {
            let mut list = LinkedList::new();
            for _ in 0..ITERS {
                list.push_back(1u8);
            }
            for _ in 0..ITERS {
                black_box(list.pop_back());
            }
            black_box(list);
        })
    });

    group.bench_function(BenchmarkId::new("Deque", ""), |b| {
        b.iter(|| {
            let mut deque = VecDeque::new();
            for _ in 0..ITERS {
                deque.push_back(1u8);
            }
            for _ in 0..ITERS {
                black_box(deque.pop_back());
            }
            black_box(deque);
        })
    });
}

fn bench_split_append(b: &mut Criterion) {
    let mut group = b.benchmark_group("Split & Append");

    let mut list = LinkedList::new();
    for _ in 0..ITERS {
        list.push_back(1u8);
    }
    group.bench_function(BenchmarkId::new("List", ""), |b| {
        b.iter(|| {
            for _ in 0..(ITERS/64) {
                let mut new_list = list.split_off(ITERS / 2);
                list.append(&mut new_list);
                black_box(&mut list);
            }
        })
    });

    let mut deque = VecDeque::new();
    for _ in 0..ITERS {
        deque.push_back(1u8);
    }
    group.bench_function(BenchmarkId::new("Deque", ""), |b| {
        b.iter(|| {
            for _ in 0..(ITERS/64) {
                let mut new_deque = deque.split_off(ITERS / 2);
                deque.append(&mut new_deque);
                black_box(&mut deque);
            }
        })
    });
}

criterion_group! {benches,
    bench_insert_back, bench_insert_front,
    bench_sum, bench_insert_remove, bench_split_append,
}

criterion_main!(benches);
