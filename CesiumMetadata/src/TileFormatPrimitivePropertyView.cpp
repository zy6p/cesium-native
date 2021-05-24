#include "CesiumMetadata/TileFormatPrimitivePropertyView.h"

namespace CesiumMetadata {
TileFormatPrimitivePropertyView::TileFormatPrimitivePropertyView(
    gsl::span<std::byte> bufferView,
    TileFormatComponentType componentType,
    size_t batchLength)
    : _bufferView{bufferView},
      _componentType{componentType},
      _batchLength{batchLength} {}

gsl::span<const uint8_t> TileFormatPrimitivePropertyView::asUint8() const {
  if (_componentType == TileFormatComponentType::UnsignedByte) {
    return gsl::span<const uint8_t>(
        reinterpret_cast<const uint8_t*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<const uint8_t>();
}

gsl::span<uint8_t> TileFormatPrimitivePropertyView::asUint8() {
  if (_componentType == TileFormatComponentType::UnsignedByte) {
    return gsl::span<uint8_t>(
        reinterpret_cast<uint8_t*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<uint8_t>();
}

gsl::span<const int8_t> TileFormatPrimitivePropertyView::asInt8() const {
  if (_componentType == TileFormatComponentType::Byte) {
    return gsl::span<const int8_t>(
        reinterpret_cast<const int8_t*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<const int8_t>();
}

gsl::span<int8_t> TileFormatPrimitivePropertyView::asInt8() {
  if (_componentType == TileFormatComponentType::Byte) {
    return gsl::span<int8_t>(
        reinterpret_cast<int8_t*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<int8_t>();
}

gsl::span<const uint16_t> TileFormatPrimitivePropertyView::asUint16() const {
  if (_componentType == TileFormatComponentType::UnsignedShort) {
    return gsl::span<const uint16_t>(
        reinterpret_cast<const uint16_t*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<const uint16_t>();
}

gsl::span<uint16_t> TileFormatPrimitivePropertyView::asUint16() {
  if (_componentType == TileFormatComponentType::UnsignedShort) {
    return gsl::span<uint16_t>(
        reinterpret_cast<uint16_t*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<uint16_t>();
}

gsl::span<const int16_t> TileFormatPrimitivePropertyView::asInt16() const {
  if (_componentType == TileFormatComponentType::Short) {
    return gsl::span<const int16_t>(
        reinterpret_cast<const int16_t*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<const int16_t>();
}

gsl::span<int16_t> TileFormatPrimitivePropertyView::asInt16() {
  if (_componentType == TileFormatComponentType::Short) {
    return gsl::span<int16_t>(
        reinterpret_cast<int16_t*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<int16_t>();
}

gsl::span<const uint32_t> TileFormatPrimitivePropertyView::asUint32() const {
  if (_componentType == TileFormatComponentType::UnsignedInt) {
    return gsl::span<const uint32_t>(
        reinterpret_cast<const uint32_t*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<const uint32_t>();
}

gsl::span<uint32_t> TileFormatPrimitivePropertyView::asUint32() {
  if (_componentType == TileFormatComponentType::UnsignedInt) {
    return gsl::span<uint32_t>(
        reinterpret_cast<uint32_t*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<uint32_t>();
}

gsl::span<const int32_t> TileFormatPrimitivePropertyView::asInt32() const {
  if (_componentType == TileFormatComponentType::Int) {
    return gsl::span<const int32_t>(
        reinterpret_cast<const int32_t*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<const int32_t>();
}

gsl::span<int32_t> TileFormatPrimitivePropertyView::asInt32() {
  if (_componentType == TileFormatComponentType::Int) {
    return gsl::span<int32_t>(
        reinterpret_cast<int32_t*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<int32_t>();
}

gsl::span<const uint64_t> TileFormatPrimitivePropertyView::asUint64() const {
  return gsl::span<const uint64_t>();
}

gsl::span<uint64_t> TileFormatPrimitivePropertyView::asUint64() {
  return gsl::span<uint64_t>();
}

gsl::span<const int64_t> TileFormatPrimitivePropertyView::asInt64() const {
  return gsl::span<const int64_t>();
}

gsl::span<int64_t> TileFormatPrimitivePropertyView::asInt64() {
  return gsl::span<int64_t>();
}

gsl::span<const float> TileFormatPrimitivePropertyView::asFloat() const {
  if (_componentType == TileFormatComponentType::Float) {
    return gsl::span<const float>(
        reinterpret_cast<const float*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<const float>();
}

gsl::span<float> TileFormatPrimitivePropertyView::asFloat() {
  if (_componentType == TileFormatComponentType::Float) {
    return gsl::span<float>(
        reinterpret_cast<float*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<float>();
}

gsl::span<const double> TileFormatPrimitivePropertyView::asDouble() const {
  if (_componentType == TileFormatComponentType::Double) {
    return gsl::span<const double>(
        reinterpret_cast<const double*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<const double>();
}

gsl::span<double> TileFormatPrimitivePropertyView::asDouble() {
  if (_componentType == TileFormatComponentType::Double) {
    return gsl::span<double>(
        reinterpret_cast<double*>(_bufferView.data()),
        _batchLength);
  }

  return gsl::span<double>();
}
} // namespace CesiumMetadata