#pragma once

#include "CesiumMetadata/ArrayPropertyView.h"
#include "CesiumMetadata/TileFormatDataType.h"
#include <GSL/span>
#include <cstddef>

namespace CesiumMetadata {
class TileFormatArrayPropertyView : public ArrayPropertyView {
public:
  TileFormatArrayPropertyView(
      gsl::span<std::byte> bufferView,
      TileFormatType type,
      TileFormatComponentType componentType,
      size_t batchLength);

  virtual size_t numOfInstances() const override;

  virtual gsl::span<const uint8_t>
  getInstanceAsUint8(size_t instance) const override;

  virtual gsl::span<uint8_t> getInstanceAsUint8(size_t instance) override;

  virtual gsl::span<const int8_t>
  getInstanceAsInt8(size_t instance) const override;

  virtual gsl::span<int8_t> getInstanceAsInt8(size_t instance) override;

  virtual gsl::span<const uint16_t>
  getInstanceAsUint16(size_t instance) const override;

  virtual gsl::span<uint16_t> getInstanceAsUint16(size_t instance) override;

  virtual gsl::span<const int16_t>
  getInstanceAsInt16(size_t instance) const override;

  virtual gsl::span<int16_t> getInstanceAsInt16(size_t instance) override;

  virtual gsl::span<const uint32_t>
  getInstanceAsUint32(size_t instance) const override;

  virtual gsl::span<uint32_t> getInstanceAsUint32(size_t instance) override;

  virtual gsl::span<const int32_t>
  getInstanceAsInt32(size_t instance) const override;

  virtual gsl::span<int32_t> getInstanceAsInt32(size_t instance) override;

  virtual gsl::span<const uint64_t>
  getInstanceAsUint64(size_t instance) const override;

  virtual gsl::span<uint64_t> getInstanceAsUint64(size_t instance) override;

  virtual gsl::span<const int64_t>
  getInstanceAsInt64(size_t instance) const override;

  virtual gsl::span<int64_t> getInstanceAsInt64(size_t instance) override;

  virtual gsl::span<const float>
  getInstanceAsFloat(size_t instance) const override;

  virtual gsl::span<float> getInstanceAsFloat(size_t instance) override;

  virtual gsl::span<const double>
  getInstanceAsDouble(size_t instance) const override;

  virtual gsl::span<double> getInstanceAsDouble(size_t instance) override;

private:
  gsl::span<std::byte> _bufferView;
  TileFormatType _type;
  TileFormatComponentType _componentType;
  size_t _batchLength;
  size_t _componentCount;
  size_t _stride;
};
} // namespace CesiumMetadata