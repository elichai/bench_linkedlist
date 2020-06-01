goos: linux <br/>
goarch: amd64 <br/>
pkg: bench_linkedlist/go <br/>
BenchmarkInsertBackList-16                 16270             **73546** ns/op <br/>
BenchmarkInsertBackSlice-16               541174              **1900** ns/op <br/>
BenchmarkInsertFrontList-16                16568             **71987** ns/op <br/>
BenchmarkInsertFrontSlice-16                2764            **394781** ns/op <br/>
BenchmarkSumtList-16                      344916              **3335** ns/op <br/>
BenchmarkSumSlice-16                     2474200               **487** ns/op <br/>
BenchmarkInsertRemoveList-16               13970             **85013** ns/op <br/>
BenchmarkInsertRemoveSlice-16             281757              **3562** ns/op <br/>
PASS <br/>
ok      bench_linkedlist/go     13.009s <br/>
