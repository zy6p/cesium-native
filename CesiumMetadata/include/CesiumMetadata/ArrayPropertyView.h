#pragma once

#include "CesiumMetadata/PropertyView.h"
#include <GSL/span>
#include <cstdint>

namespace CesiumMetadata {
class ArrayPropertyView : public PropertyView {
public:
  virtual ~ArrayPropertyView() noexcept = default;

  virtual ArrayPropertyView* asArrayPropertyView() noexcept override {
    return this;
  }

  virtual const ArrayPropertyView*
  asArrayPropertyView() const noexcept override {
    return this;
  }

  virtual size_t numOfInstances() const = 0;

  virtual gsl::span<const uint8_t>
  getInstanceAsUint8(size_t instance) const = 0;

  virtual gsl::span<uint8_t> getInstanceAsUint8(size_t instance) = 0;

  virtual gsl::span<const int8_t> getInstanceAsInt8(size_t instance) const = 0;

  virtual gsl::span<int8_t> getInstanceAsInt8(size_t instance) = 0;

  virtual gsl::span<const uint16_t>
  getInstanceAsUint16(size_t instance) const = 0;

  virtual gsl::span<uint16_t> getInstanceAsUint16(size_t instance) = 0;

  virtual gsl::span<const int16_t>
  getInstanceAsInt16(size_t instance) const = 0;

  virtual gsl::span<int16_t> getInstanceAsInt16(size_t instance) = 0;

  virtual gsl::span<const uint32_t>
  getInstanceAsUint32(size_t instance) const = 0;

  virtual gsl::span<uint32_t> getInstanceAsUint32(size_t instance) = 0;

  virtual gsl::span<const int32_t>
  getInstanceAsInt32(size_t instance) const = 0;

  virtual gsl::span<int32_t> getInstanceAsInt32(size_t instance) = 0;

  virtual gsl::span<const uint64_t>
  getInstanceAsUint64(size_t instance) const = 0;

  virtual gsl::span<uint64_t> getInstanceAsUint64(size_t instance) = 0;

  virtual gsl::span<const int64_t>
  getInstanceAsInt64(size_t instance) const = 0;

  virtual gsl::span<int64_t> getInstanceAsInt64(size_t instance) = 0;

  virtual gsl::span<const float> getInstanceAsFloat(size_t instance) const = 0;

  virtual gsl::span<float> getInstanceAsFloat(size_t instance) = 0;

  virtual gsl::span<const double>
  getInstanceAsDouble(size_t instance) const = 0;

  virtual gsl::span<double> getInstanceAsDouble(size_t instance) = 0;
};
} // namespace CesiumMetadata