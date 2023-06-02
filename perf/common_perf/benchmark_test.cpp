#include <benchmark/benchmark.h>
#include <stdio.h>
#include <log.h>

/*TEST API*/
int factorial_pref(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

/*Necessary initialization of coupling variables*/
int vari = 0;

#if 0
static void factorial_pref_64(benchmark::State &state)
{
    uint64_t a;
    for(auto _ : state){
        // pref test code
        a = factorial_pref(64);
    }
}
BENCHMARK(factorial_pref_64)->Iterations(10);

static void factorial_pref_100(benchmark::State &state)
{
    uint64_t a;
    for(auto _ : state){
        // pref test code
        a = factorial_pref(100);
    }
}
BENCHMARK(factorial_pref_100)->Iterations(10);

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
BENCHMARK(factorial_pref_x)->Arg(10)->Arg(6);
BENCHMARK(factorial_pref_x)->RangeMultiplier(2)->Range(11, 50)->Complexity(benchmark::oAuto);
BENCHMARK(factorial_pref_x)->RangeMultiplier(2)->Range(11, 50)->Complexity(benchmark::oLogN);
BENCHMARK(factorial_pref_x)->Apply(custom_args);
BENCHMARK(factorial_pref_x)->DenseRange(1, 17, 5);
BENCHMARK(factorial_pref_xx)->Args({11, 15})->Args({2, 9});
BENCHMARK(factorial_pref_xx)->RangeMultiplier(2)->Ranges({{11, 50}, {51, 100}});

// benchmark的主函数
BENCHMARK_MAIN();

#elif 0
// Testing interaction with Fixture::Setup/Teardown
namespace fixture_interaction {
int setup = 0;
int fixture_setup = 0;
}  // namespace fixture_interaction

class Factorial_Fixture : public ::benchmark::Fixture {
public:
    void SetUp(const ::benchmark::State&) {
        fixture_interaction::fixture_setup++;
    }

    ~Factorial_Fixture() {}
};

BENCHMARK_F(Factorial_Fixture, factorial_pref_64)(benchmark::State& state) {
    uint64_t a;
    for (auto _ : state) {
        a = factorial_pref(64);
    }
}

BENCHMARK_REGISTER_F(Factorial_Fixture, factorial_pref_64)
    ->Arg(1)
    ->Arg(3)
    ->Arg(5)
    ->Iterations(100000)->Repetitions(3);

// Run the benchmark
BENCHMARK_MAIN();

#elif 0
template <typename T>
class Factorial_Fixture : public ::benchmark::Fixture {
//  public:
//   Factorial_Fixture() : data(0) {}

//   T data;
    /*公共变量*/
};

BENCHMARK_TEMPLATE_F(Factorial_Fixture, factorial_pref_64, int)(benchmark::State& st) {
    uint64_t a;
    for (auto _ : st) {
        a = factorial_pref(64);
    }
}

BENCHMARK_TEMPLATE_DEFINE_F(Factorial_Fixture, factorial_pref_100, double)(benchmark::State& st) {
    uint64_t a;
    for (auto _ : st) {
        a = factorial_pref(100);
    }
}

BENCHMARK_REGISTER_F(Factorial_Fixture, factorial_pref_100)->Threads(2);
BENCHMARK_REGISTER_F(Factorial_Fixture, factorial_pref_100)->Unit(benchmark::kNanosecond);
BENCHMARK_REGISTER_F(Factorial_Fixture, factorial_pref_100)->Unit(benchmark::kMicrosecond);
BENCHMARK_REGISTER_F(Factorial_Fixture, factorial_pref_100)->Unit(benchmark::kMillisecond);
BENCHMARK_REGISTER_F(Factorial_Fixture, factorial_pref_100)->Unit(benchmark::kSecond);
BENCHMARK_MAIN();
#elif 0
static void DoSetup(const benchmark::State& state) {
    printf("in function.\n");
}

static void DoTeardown(const benchmark::State& state) {
    printf("out function.\n");
}

static void test_func(benchmark::State& state) {
    uint64_t a;
    for (auto _ : state) {
        a = factorial_pref(64);
    }
    // printf("inter function.\n");
}

BENCHMARK(test_func)->Arg(1)->Arg(3)->Threads(16)->Threads(32)->Setup(DoSetup)->Teardown(DoTeardown)->Iterations(1)->Name("test_func_xx");
/*运行机制*/
/*
202872
|Setup--test_func(参数)--Teardown|
*/
#elif 1
class Factorial_Fixture : public benchmark::Fixture {
public:
//   void SetUp(const ::benchmark::State& state) {
//     // printf("SetUp function.\n");
//   }

//   void TearDown(const ::benchmark::State& state) {
//     // printf("TearDown function.\n");
//   }
  uint64_t a;
};

uint64_t b = 80;
void __test(const benchmark::State& state) {
   // printf("test numbers = %ld.\n", b);
}

static void __setup(const benchmark::State& state) {
   // printf("in function.\n");
}

static void __teardown(const benchmark::State& state) {
    // printf("out function.\n");
}

BENCHMARK_F(Factorial_Fixture, factorial_pref_64)(benchmark::State& st) {
    for (auto _ : st) {
        a = factorial_pref(64);
    }
    // printf("Inter function.\n");
}

BENCHMARK_DEFINE_F(Factorial_Fixture, factorial_pref_65)(benchmark::State& st) {
    for (auto _ : st) {
        a = factorial_pref(65);
    }
    // printf("Inter function.\n");
}

BENCHMARK_DEFINE_F(Factorial_Fixture, factorial_pref_100)(benchmark::State& st) {
    double numFoos = 0, numBars = 0, numBazs = 0;
    for (auto _ : st) {
        a = factorial_pref(100);
        numBars++;
        numFoos++;
        numBazs++;
    }
    // printf("Inter function %ld.\n", b);
    st.counters["Foo"] = numFoos;
    st.counters["Bar"] = numBars;
    st.counters["Baz"] = numBazs;
    st.counters["FooRate"] = benchmark::Counter(numFoos, benchmark::Counter::kIsRate);
    st.counters["FooInvRate"] = benchmark::Counter(numFoos, benchmark::Counter::kIsRate | benchmark::Counter::kInvert);
    st.counters["FooAvg"] = benchmark::Counter(numFoos, benchmark::Counter::kAvgThreads);
    st.counters["FooAvgRate"] = benchmark::Counter(numFoos,benchmark::Counter::kAvgThreadsRate);
    //st.counters["BytesProcessed"] = benchmark::Counter(st.range(0), benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1024);
}
/* BarTest is NOT registered */
// BENCHMARK_REGISTER_F(Factorial_Fixture, factorial_pref_100)->Threads(100)->Iterations(1)->ThreadRange(1, 8)->UseRealTime();
// BENCHMARK_REGISTER_F(Factorial_Fixture, factorial_pref_100)->Setup(__setup)->Teardown(__teardown);
// BENCHMARK_REGISTER_F(Factorial_Fixture, factorial_pref_100)->Setup(__test)->Teardown(__teardown)->Arg(4<<10)->Range(4, 8<<10);
// BENCHMARK_REGISTER_F(Factorial_Fixture, factorial_pref_100)->Setup(__test)->Teardown(__teardown)->Args({1<<10, 128, 64});
// BENCHMARK_REGISTER_F(Factorial_Fixture, factorial_pref_100)->Setup(__test)->Teardown(__teardown)->Ranges({{1<<10, 8<<10}, {128, 512}});
BENCHMARK_REGISTER_F(Factorial_Fixture, factorial_pref_65)->Setup(__test)->Teardown(__teardown)->ArgsProduct({{1, 3, 8}, {20, 40, 60, 80}});
BENCHMARK_REGISTER_F(Factorial_Fixture, factorial_pref_65)->Setup(__test)->Teardown(__teardown)->Repetitions(10);
/* BarTest is now registered */

#else

#endif