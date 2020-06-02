# Benchmarks for linkedlist implementations in various languages

The point of this repository is to show that it's almost never a good idea to use a linked list, in any language.

Any PRs for new languages / more efficient implementations (only types provided by the language though) are welcome :)

This currently contain the following benchmarks:
1. Inserting elements to the back. (2048 times)
2. Inserting elements to the front. (2048 times)
3. Summing up all the elements. (2048 times)
4. Inserting elements to the back and then removing them. (2048 times)
5. Spliting the list and the middle and re-appending it. (32 times)

All the benchmarks were down with a `2048` number of iterations per operation (e.g. pushing elements, one by one to the list, or summing up a list with 2048 elements)
The results are from the spec of my laptop: Linux, Intel i9-9980HK 2.4Ghz. 32GB RAM.

I've chosen 2048 elements because I believe it's a moderate size list. (it can be easily changed via the constant ITERS in all benchmarks)

## Rust
[Full Results](rust/results) <br/>
Full report: [Criterion Report](https://htmlpreview.github.io/?https://github.com/elichai/bench_linkedlist/blob/master/rust/target/criterion/report/index.html)

| Name              | Speed            |
|-------------------|------------------|
| InsertBackList    |<div align="right">**28,938** ns/op</div>|
| InsertBackDeque   |<div align="right">**4,519** ns/op</div> |
| InsertFrontList   |<div align="right">**51,762** ns/op</div>|
| InsertFrontDeque  |<div align="right">**5,686** ns/op</div> |
| SumList           |<div align="right">**2,946** ns/op</div> |
| SumDeque          |<div align="right">**259** ns/op</div>   |
| InsertRemoveList  |<div align="right">**54,783** ns/op</div>|
| InsertRemoveDeque |<div align="right">**7,399** ns/op</div> |
| SpliAndAppendList |<div align="right">**41,430** ns/op</div>|
| SpliAndAppendDeque|<div align="right">**61,606** ns/op</div>|

`std::collections::VecDeque` is orders of magnitude faster in all operations.<br/>
if inserting to the front isn't needed then `std::vec::Vec` is even faster.

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
Go's List doesn't allow splitting a list into 2 so I did not implement that benchmark.

## C++
[Full Results](cpp/results) <br/>
| Name              | Speed            |
|-------------------|------------------|
| InsertBackList    |<div align="right">**31,304** ns/op</div> |
| InsertBackDeque   |<div align="right">**2,830** ns/op</div>  |
| InsertFrontList   |<div align="right">**32,644** ns/op</div> |
| InsertFrontDeque  |<div align="right">**2,878** ns/op</div>  |
| SumList           |<div align="right">**3,679** ns/op</div>  |
| SumDeque          |<div align="right">**1,109** ns/op</div>    |
| InsertRemoveList  |<div align="right">**36,793** ns/op</div> |
| InsertRemoveDeque |<div align="right">**6,694** ns/op</div>  |
| SpliAndAppendList |<div align="right">**130,769** ns/op</div>|
| SpliAndAppendDeque|<div align="right">**4,794** ns/op</div>|


`std::deque` is orders of magnitude in all the operations I've tested. <br/>
If inserting to the front isn't needed then `std::vector` is even faster than `std::deque`.