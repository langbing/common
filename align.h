#pragma once

template <typename T>
inline constexpr T align_up(T v, T align) {
      return (v + align - 1) & ~(align - 1);
}

template <typename T>
inline constexpr T align_down(T v, T align) {
      return v & ~(align - 1);
}

template <typename T>
inline constexpr T align(T v, T align) {
      return v & (align - 1);
}
