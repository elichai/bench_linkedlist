goos: linux <br/>
goarch: amd64 <br/>
pkg: bench_linkedlist/go <br/>
| Name                          | Iterations| Speed          |
|-------------------------------|---------|------------------|
| BenchmarkInsertBackList-16    | 16270   |  **73546** ns/op |
| BenchmarkInsertBackSlice-16   | 541174  |   **1900** ns/op |
| BenchmarkInsertFrontList-16   | 16568   |  **71987** ns/op |
| BenchmarkInsertFrontSlice-16  | 2764    | **394781** ns/op |
| BenchmarkSumtList-16          | 344916  |   **3335** ns/op |
| BenchmarkSumSlice-16          | 2474200 |    **487** ns/op |
| BenchmarkInsertRemoveList-16  | 13970   |  **85013** ns/op |
| BenchmarkInsertRemoveSlice-16 | 281757  |   **3562** ns/op |

PASS <br/>
ok      bench_linkedlist/go     13.009s <br/>
