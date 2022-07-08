# utl

Header-only utility library (`utl::` namespace stands for __UTiL__) with small, simple and common functions, which nevertheless weren't present in C++17 standard library. All functions that can be `constexpr` are. Not intended to become anything serious, but you may find some parts really useful, for example `"float.h"` has IEE 754 half-precision floating point conversion functions. I use this library in many projects for embedded systems and in my other libraries, e.g. [zbor][1].

## Dependencies __(not up to date!)__

There are no dependencies on `std::`, basic requirements are `cstdint` and `cstddef`. Additionally, `ctime` required for 
`"time.h"`. `cctype` and `cstdio` (only for `putchar`) used in `"log.h"`.

## TODO

- [ ] readme
- [ ] tests
- [ ] maybe restrict / remove bit offset in `log_bits()` ?

[1]: https://github.com/nth-eye/zbor