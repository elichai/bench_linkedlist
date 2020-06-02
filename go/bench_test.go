package bench

import (
	"container/list"
	"testing"
)

const ITERS = 2048

func BenchmarkInsertBackList(b *testing.B) {
	for n := 0; n < b.N; n++ {
		l := list.New()

		for i := 0; i < ITERS; i++ {
			l.PushBack(byte(1))
		}
	}
}

func BenchmarkInsertBackSlice(b *testing.B) {
	for n := 0; n < b.N; n++ {
		slice := []byte{}

		for i := 0; i < ITERS; i++ {
			slice = append(slice, byte(1))
		}
	}
}

func BenchmarkInsertFrontList(b *testing.B) {
	for n := 0; n < b.N; n++ {
		l := list.New()

		for i := 0; i < ITERS; i++ {
			l.PushFront(byte(1))
		}
	}
}

func BenchmarkInsertFrontSlice(b *testing.B) {
	for n := 0; n < b.N; n++ {
		slice := []byte{}

		for i := 0; i < ITERS; i++ {
			slice = append([]byte{1}, slice...)
		}
	}
}

func BenchmarkSumList(b *testing.B) {
	l := list.New()
	for i := 0; i < ITERS; i++ {
		l.PushBack(byte(1))
	}

	b.ResetTimer()
	for n := 0; n < b.N; n++ {
		for e := l.Front(); e != nil; e = e.Next() {
			var sum uint = 0
			sum += uint(e.Value.(byte))
		}
	}
}

func BenchmarkSumSlice(b *testing.B) {
	slice := []byte{}

	for i := 0; i < ITERS; i++ {
		slice = append(slice, byte(1))
	}

	b.ResetTimer()
	for n := 0; n < b.N; n++ {
		var sum uint = 0
		for _, n := range slice {
			sum += uint(n)
		}

	}
}

func BenchmarkInsertRemoveList(b *testing.B) {
	for n := 0; n < b.N; n++ {
		l := list.New()

		for i := 0; i < ITERS; i++ {
			l.PushBack(byte(1))
		}

		last := l.Front()
		for e := l.Back(); e != nil; e = e.Prev() {
			l.Remove(last)
			last = e
		}
		l.Remove(last)

	}
}

func BenchmarkInsertRemoveSlice(b *testing.B) {
	for n := 0; n < b.N; n++ {
		slice := []byte{}

		for i := 0; i < ITERS; i++ {
			slice = append(slice, byte(1))
		}

		for range slice {
			slice = slice[:len(slice)-1]
		}

	}
}
