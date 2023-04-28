#include <benchmark/benchmark.h>
#include <stdio.h>
#include <log.h>

int factorial_pref(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
//   log_fatal("%s, factorial result = %d.\n", __func__, result);
//   log_debug("%s, n = %d.\n", __func__, n);

  return result;
}

#if 1
static void factorial_pref_64(benchmark::State &state)
{
    uint64_t a;
    for(auto _ : state){
        // pref test code
        a = factorial_pref(64);
    }
}

static void factorial_pref_100(benchmark::State &state)
{
    uint64_t a;
    for(auto _ : state){
        // pref test code
        a = factorial_pref(64);
    }
}

static void factorial_pref_x(benchmark::State &state)
{
    uint64_t a;
    int64_t b = state.range(0);
    // printf("b = %ld.\n", b);
    for(auto _ : state){
        // pref test code
        a = factorial_pref(b);
    }
    state.SetComplexityN(state.range(0));
}

static void factorial_pref_xx(benchmark::State &state)
{
    uint64_t a;
    int64_t b = state.range(0);
    int64_t c = state.range(1);
    // printf("b = %ld, c = %ld.\n", b, c);
    for(auto _ : state){
        // pref test code
        a = factorial_pref(b);
    }
}


// 参数生成器
static void custom_args(benchmark::internal::Benchmark* b)
{
    for(int i = 0; i < 10; i++){
        b->Arg(i);
    }
}

// 注册测试用例
// BENCHMARK(factorial_pref_64);
// BENCHMARK(factorial_pref_100)->Iterations(10);
// BENCHMARK(factorial_pref_x)->Arg(10)->Arg(6);
BENCHMARK(factorial_pref_x)->RangeMultiplier(2)->Range(11, 50)->Complexity(benchmark::oAuto);
BENCHMARK(factorial_pref_x)->RangeMultiplier(2)->Range(11, 50)->Complexity(benchmark::oLogN);
// BENCHMARK(factorial_pref_x)->Apply(custom_args);
// BENCHMARK(factorial_pref_x)->DenseRange(1, 17, 5);
// BENCHMARK(factorial_pref_xx)->Args({11, 15})->Args({2, 9});
// BENCHMARK(factorial_pref_xx)->RangeMultiplier(2)->Ranges({{11, 50}, {51, 100}});

// benchmark的主函数
BENCHMARK_MAIN();
#else

#endif