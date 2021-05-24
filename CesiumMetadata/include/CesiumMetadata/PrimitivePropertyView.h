#pragma once

#include "CesiumMetadata/PropertyView.h"
#include <GSL/span>
#include <cstdint>

namespace CesiumMetadata {
class PrimitivePropertyView : public PropertyView {
public:
  virtual ~PrimitivePropertyView() noexcept = default;

  virtual PrimitivePropertyView* asPrimitivePropertyView() noexcept override {
    return this;
  }

  virtual const PrimitivePropertyView*
  asPrimitivePropertyView() const noexcept override {
    return this;
  }

  virtual gsl::span<const uint8_t> asUint8() const = 0;

  virtual gsl::span<uint8_t> asUint8() = 0;

  virtual gsl::span<const int8_t> asInt8() const = 0;

  virtual gsl::span<int8_t> asInt8() = 0;

  virtual gsl::span<const uint16_t> asUint16() const = 0;

  virtual gsl::span<uint16_t> asUint16() = 0;

  virtual gsl::span<const int16_t> asInt16() const = 0;

  virtual gsl::span<int16_t> asInt16() = 0;

  virtual gsl::span<const uint32_t> asUint32() const = 0;

  virtual gsl::span<uint32_t> asUint32() = 0;

  virtual gsl::span<const int32_t> asInt32() const = 0;

  virtual gsl::span<int32_t> asInt32() = 0;

  virtual gsl::span<const uint64_t> asUint64() const = 0;

  virtual gsl::span<uint64_t> asUint64() = 0;

  virtual gsl::span<const int64_t> asInt64() const = 0;

  virtual gsl::span<int64_t> asInt64() = 0;

  virtual gsl::span<const float> asFloat() const = 0;

  virtual gsl::span<float> asFloat() = 0;

  virtual gsl::span<const double> asDouble() const = 0;

  virtual gsl::span<double> asDouble() = 0;
};
} // namespace CesiumMetadata