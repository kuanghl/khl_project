// #define ANKERL_NANOBENCH_IMPLEMENT
#include <nanobench.h>
#include <atomic>
#include <random>
#include <unistd.h>

namespace {

// Benchmarks how fast we can get 64bit random values from Rng.
template <typename Rng>
void bench(ankerl::nanobench::Bench* bench, char const* name) {
    std::random_device dev;
    Rng rng(dev());

    bench->run(name, [&]() {
        auto r = std::uniform_int_distribution<uint64_t>{}(rng);
        ankerl::nanobench::doNotOptimizeAway(r);
    });
}

} // namespace

int main() {
    double d = 1.0;
    ankerl::nanobench::Bench().run("some double ops", [&] {
        d += 1.0 / d;
        // sleep(2);
        if (d > 5.0) {
            d -= 5.0;
        }
        // ankerl::nanobench::doNotOptimizeAway(d);
    });

    int y = 0;
    std::atomic<int> x(0);
    ankerl::nanobench::Bench().run("compare_exchange_strong", [&] {
        x.compare_exchange_strong(y, 0);
    });

    uint64_t xx = 1;
    ankerl::nanobench::Bench().run("++xx", [&]() {
        ankerl::nanobench::doNotOptimizeAway(xx += 1);
    });

    std::random_device dev;
    std::mt19937_64 rng(dev());
    ankerl::nanobench::Bench().run("random fluctuations", [&] {
        // each run, perform a random number of rng calls
        auto iterations = rng() & UINT64_C(0xff);
        for (uint64_t i = 0; i < iterations; ++i) {
            ankerl::nanobench::doNotOptimizeAway(rng());
        }
    });

    // perform a few warmup calls, and since the runtime is not always stable
    // for each generator, increase the number of epochs to get more accurate
    // numbers.
    ankerl::nanobench::Bench b;
    b.title("Random Number Generators")
        .unit("uint64_t")
        .warmup(100)
        .relative(true);
    b.performanceCounters(true);

    // sets the first one as the baseline
    bench<std::default_random_engine>(&b, "std::default_random_engine");
    bench<std::mt19937>(&b, "std::mt19937");
    bench<std::mt19937_64>(&b, "std::mt19937_64");
    bench<std::ranlux24_base>(&b, "std::ranlux24_base");
    bench<std::ranlux48_base>(&b, "std::ranlux48_base");
    bench<std::ranlux24>(&b, "std::ranlux24_base");
    bench<std::ranlux48>(&b, "std::ranlux48");
    bench<std::knuth_b>(&b, "std::knuth_b");
    bench<ankerl::nanobench::Rng>(&b, "ankerl::nanobench::Rng");
}