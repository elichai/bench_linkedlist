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
    group.bench_function(BenchmarkId::new("Vec", ""), |b| {
        b.iter(|| {
            let mut vec = VecDeque::new();
            for _ in 0..ITERS {
                vec.push_back(1u8);
            }
            black_box(vec);
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
    group.bench_function(BenchmarkId::new("Vec", ""), |b| {
        b.iter(|| {
            let mut vec = VecDeque::new();
            for _ in 0..ITERS {
                vec.push_front(1u8);
            }
            black_box(vec);
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

    let mut vec = VecDeque::from(vec![1u8; ITERS]);
    group.bench_function(BenchmarkId::new("Vec", ""), |b| {
        b.iter(|| {
            let sum: usize = vec.iter().map(|a| *a as usize).sum();
            black_box(sum);
            black_box(&mut vec);
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

    group.bench_function(BenchmarkId::new("Vec", ""), |b| {
        b.iter(|| {
            let mut vec = VecDeque::new();
            for _ in 0..ITERS {
                vec.push_back(1u8);
            }
            for _ in 0..ITERS {
                black_box(vec.pop_back());
            }
            black_box(vec);
        })
    });
}

criterion_group! {benches,
    bench_insert_back, bench_insert_front, bench_sum, bench_insert_remove
}

criterion_main!(benches);
