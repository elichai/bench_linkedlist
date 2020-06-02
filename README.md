# Benchmarks for linkedlist implementations in various languages

This currently contain the following benchmarks:
1. Inserting elements to the back.
2. Inserting elements to the front.
3. Summing up all the elements.
4. Inserting elements to the back and then removing them.

All the benchmarks were down with a `2048` number of iterations per operation (e.g. pushing 2048 elements, one by one to the list, or summing up a list with 2048 elements)
The results are from the spec of my laptop: Linux, Intel i9-9980HK 2.4Ghz. 32GB RAM.


## Rust
[Full Results](rust/results) <br/>
Full report: [Criterion Report](https://htmlpreview.github.io/?https://github.com/elichai/bench_linkedlist/blob/master/rust/target/criterion/report/index.html)

| Name              | Speed            |
|-------------------|------------------|
| InsertBackList    |<div align="right">**27,010** ns/op</div>|
| InsertBackDeque   |<div align="right">**4,349** ns/op</div> |
| InsertFrontList   |<div align="right">**50,515** ns/op</div>|
| InsertFrontDeque  |<div align="right">**5,3643** ns/op</div>|
| SumList           |<div align="right">**3,9141** ns/op</div>|
| SumDeque          |<div align="right">**251** ns/op</div>   |
| InsertRemoveList  |<div align="right">**52,267** ns/op</div>|
| InsertRemoveDeque |<div align="right">**7,055** ns/op</div> |

`std::collections::VecDeque` is orders of magnitude faster in all operations for a moderate size vec (2048 1byte elements).<br/>
if inserting to the front isn't needed then `std::vec::Vec` is even faster

## Golang
[Full Results](go/results) <br/>
| Name              | Speed            |
|-------------------|------------------|
| InsertBackList    |<div align="right">**73,546** ns/op</div> |
| InsertBackSlice   |<div align="right">**1,900** ns/op</div>  |
| InsertFrontList   |<div align="right">**71,987** ns/op</div> |
| InsertFrontSlice  |<div align="right">**394,781** ns/op</div>|
| SumList           |<div align="right">**3,335** ns/op</div>  |
| SumSlice          |<div align="right">**487** ns/op</div>    |
| InsertRemoveList  |<div align="right">**85,013** ns/op</div> |
| InsertRemoveSlice |<div align="right">**3,562** ns/op</div>  |


Go's builtin slice is orders of magnitude faster than stdlib's `container/list`, except when inserting to the front, where the slice's implementation isn't optimized for that (and the stdlib doesn't provide a Deque library),  <br/>
this can be optimizer with a simple Deque implementation.

## C++
[Full Results](cpp/results) <br/>
| Name              | Speed            |
|-------------------|------------------|
| InsertBackList    |<div align="right">**33,950** ns/op</div> |
| InsertBackDeque   |<div align="right">**3,022** ns/op</div>  |
| InsertFrontList   |<div align="right">**35,887** ns/op</div> |
| InsertFrontDeque  |<div align="right">**3,291** ns/op</div>  |
| SumList           |<div align="right">**4,948** ns/op</div>  |
| SumDeque          |<div align="right">**812** ns/op</div>    |
| InsertRemoveList  |<div align="right">**37,419** ns/op</div> |
| InsertRemoveDeque |<div align="right">**6,907** ns/op</div>  |

`std::deque` is orders of magnitude in all the operations I've tested for a moderate size deque(2048 uint8_t elements). <br/>
If inserting to the front isn't needed then `std::vector` is even faster than `std::deque`.