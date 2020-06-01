# Benchmarks for linkedlist implementations in different languages


## Rust
[Results](rust/RESULTS.md) <br/>
Full report: [Criterion Report](https://htmlpreview.github.io/?https://github.com/elichai/bench_linkedlist/blob/master/rust/target/criterion/report/index.html)

`std::collections::VecDeque` is orders of magnitude faster in all operations for a moderate size vec (2048 1byte elements).
if inserting to the front isn't needed then `std::vec::Vec` is even faster
