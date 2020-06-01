# Benchmarks for linkedlist implementations in different languages


## Rust
[Results](rust/RESULTS.md) <br/>
Full report: [Criterion Report](https://htmlpreview.github.io/?https://github.com/elichai/bench_linkedlist/blob/master/rust/target/criterion/report/index.html)

`std::collections::VecDeque` is orders of magnitude faster in all operations for a moderate size vec (2048 1byte elements).
if inserting to the front isn't needed then `std::vec::Vec` is even faster

## Golang
[Results](go/RESULTS.md) <br/>

Go's builtin slice is orders of magnitude faster than stdlib's `container/list`, except when inserting to the front, where the slice's implementation isn't optimized for that (and the stdlib doesn't provide a Deque library), this can be optimizer with a simple Deque implementation.