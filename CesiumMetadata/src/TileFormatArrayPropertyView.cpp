#include "CesiumMetadata/TileFormatArrayPropertyView.h"
#include <cassert>

namespace CesiumMetadata {
TileFormatArrayPropertyView::TileFormatArrayPropertyView(
    gsl::span<std::byte> bufferView,
    TileFormatType type,
    TileFormatComponentType componentType,
    size_t batchLength)
    : _bufferView{bufferView},
      _type{type},
      _componentType{componentType},
      _batchLength{batchLength} {
  _componentCount = getNumOfComponents(type);
  _stride = getComponentSize(componentType) * _componentCount;
}

size_t TileFormatArrayPropertyView::numOfInstances() const {
  return _batchLength;
}

gsl::span<const uint8_t>
TileFormatArrayPropertyView::getInstanceAsUint8(size_t instance) const {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::UnsignedByte) {
    return gsl::span<const uint8_t>(
        reinterpret_cast<const uint8_t*>(
            _bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<const uint8_t>();
}

gsl::span<uint8_t>
TileFormatArrayPropertyView::getInstanceAsUint8(size_t instance) {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::UnsignedByte) {
    return gsl::span<uint8_t>(
        reinterpret_cast<uint8_t*>(_bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<uint8_t>();
}

gsl::span<const int8_t>
TileFormatArrayPropertyView::getInstanceAsInt8(size_t instance) const {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::Byte) {
    return gsl::span<const int8_t>(
        reinterpret_cast<const int8_t*>(
            _bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<const int8_t>();
}

gsl::span<int8_t>
TileFormatArrayPropertyView::getInstanceAsInt8(size_t instance) {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::Byte) {
    return gsl::span<int8_t>(
        reinterpret_cast<int8_t*>(_bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<int8_t>();
}

gsl::span<const uint16_t>
TileFormatArrayPropertyView::getInstanceAsUint16(size_t instance) const {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::UnsignedShort) {
    return gsl::span<const uint16_t>(
        reinterpret_cast<const uint16_t*>(
            _bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<const uint16_t>();
}

gsl::span<uint16_t>
TileFormatArrayPropertyView::getInstanceAsUint16(size_t instance) {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::UnsignedShort) {
    return gsl::span<uint16_t>(
        reinterpret_cast<uint16_t*>(_bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<uint16_t>();
}

gsl::span<const int16_t>
TileFormatArrayPropertyView::getInstanceAsInt16(size_t instance) const {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::Short) {
    return gsl::span<const int16_t>(
        reinterpret_cast<const int16_t*>(
            _bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<const int16_t>();
}

gsl::span<int16_t>
TileFormatArrayPropertyView::getInstanceAsInt16(size_t instance) {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::Short) {
    return gsl::span<int16_t>(
        reinterpret_cast<int16_t*>(_bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<int16_t>();
}

gsl::span<const uint32_t>
TileFormatArrayPropertyView::getInstanceAsUint32(size_t instance) const {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::UnsignedInt) {
    return gsl::span<const uint32_t>(
        reinterpret_cast<const uint32_t*>(
            _bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<const uint32_t>();
}

gsl::span<uint32_t>
TileFormatArrayPropertyView::getInstanceAsUint32(size_t instance) {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::UnsignedInt) {
    return gsl::span<uint32_t>(
        reinterpret_cast<uint32_t*>(_bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<uint32_t>();
}

gsl::span<const int32_t>
TileFormatArrayPropertyView::getInstanceAsInt32(size_t instance) const {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::Int) {
    return gsl::span<const int32_t>(
        reinterpret_cast<const int32_t*>(
            _bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<const int32_t>();
}

gsl::span<int32_t>
TileFormatArrayPropertyView::getInstanceAsInt32(size_t instance) {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::Int) {
    return gsl::span<int32_t>(
        reinterpret_cast<int32_t*>(_bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<int32_t>();
}

gsl::span<const uint64_t>
TileFormatArrayPropertyView::getInstanceAsUint64(size_t instance) const {
  (void)(instance);
  assert(instance < _batchLength);
  return gsl::span<const uint64_t>();
}

gsl::span<uint64_t>
TileFormatArrayPropertyView::getInstanceAsUint64(size_t instance) {
  (void)(instance);
  assert(instance < _batchLength);
  return gsl::span<uint64_t>();
}

gsl::span<const int64_t>
TileFormatArrayPropertyView::getInstanceAsInt64(size_t instance) const {
  (void)(instance);
  assert(instance < _batchLength);
  return gsl::span<const int64_t>();
}

gsl::span<int64_t>
TileFormatArrayPropertyView::getInstanceAsInt64(size_t instance) {
  (void)(instance);
  assert(instance < _batchLength);
  return gsl::span<int64_t>();
}

gsl::span<const float>
TileFormatArrayPropertyView::getInstanceAsFloat(size_t instance) const {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::Float) {
    return gsl::span<const float>(
        reinterpret_cast<const float*>(_bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<const float>();
}

gsl::span<float>
TileFormatArrayPropertyView::getInstanceAsFloat(size_t instance) {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::Float) {
    return gsl::span<float>(
        reinterpret_cast<float*>(_bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<float>();
}

gsl::span<const double>
TileFormatArrayPropertyView::getInstanceAsDouble(size_t instance) const {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::Double) {
    return gsl::span<const double>(
        reinterpret_cast<const double*>(
            _bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<const double>();
}

gsl::span<double>
TileFormatArrayPropertyView::getInstanceAsDouble(size_t instance) {
  assert(instance < _batchLength);
  if (_componentType == TileFormatComponentType::Double) {
    return gsl::span<double>(
        reinterpret_cast<double*>(_bufferView.data() + instance * _stride),
        _componentCount);
  }

  return gsl::span<double>();
}
} // namespace CesiumMetadata
