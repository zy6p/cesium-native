#pragma once

#include "CesiumMetadata/PrimitivePropertyView.h"
#include "CesiumMetadata/TileFormatDataType.h"
#include <cstddef>
#include <cstdint>
#include <gsl/span>

namespace CesiumMetadata {
class TileFormatPrimitivePropertyView : public PrimitivePropertyView {
public:
  TileFormatPrimitivePropertyView(
      gsl::span<std::byte> bufferView,
      TileFormatComponentType componentType,
      size_t batchLength);

  virtual gsl::span<const uint8_t> asUint8() const override;

  virtual gsl::span<uint8_t> asUint8() override;

  virtual gsl::span<const int8_t> asInt8() const override;

  virtual gsl::span<int8_t> asInt8() override;

  virtual gsl::span<const uint16_t> asUint16() const override;

  virtual gsl::span<uint16_t> asUint16() override;

  virtual gsl::span<const int16_t> asInt16() const override;

  virtual gsl::span<int16_t> asInt16() override;

  virtual gsl::span<const uint32_t> asUint32() const override;

  virtual gsl::span<uint32_t> asUint32() override;

  virtual gsl::span<const int32_t> asInt32() const override;

  virtual gsl::span<int32_t> asInt32() override;

  virtual gsl::span<const uint64_t> asUint64() const override;

  virtual gsl::span<uint64_t> asUint64() override;

  virtual gsl::span<const int64_t> asInt64() const override;

  virtual gsl::span<int64_t> asInt64() override;

  virtual gsl::span<const float> asFloat() const override;

  virtual gsl::span<float> asFloat() override;

  virtual gsl::span<const double> asDouble() const override;

  virtual gsl::span<double> asDouble() override;

private:
  gsl::span<std::byte> _bufferView;
  TileFormatComponentType _componentType;
  size_t _batchLength;
};
} // namespace CesiumMetadata