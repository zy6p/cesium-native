#pragma once

#include "CesiumMetadata/Metadata.h"
#include <cstddef>
#include <GSL/span>
#include <memory>
#include <map>

namespace CesiumMetadata {
class PropertyView;

class BatchTableMetadata : public Metadata {
public:
  virtual PropertyView* getProperty(const std::string& propertyName) override;

  virtual const PropertyView*
  getProperty(const std::string& propertyName) const override;

  virtual void forEachProperty(
      std::function<void(const std::string& name, PropertyView& propertyView)>)
      override;

  virtual void forEachProperty(
      std::function<
          void(const std::string& name, const PropertyView& propertyView)>)
      const override;

  static std::unique_ptr<BatchTableMetadata> create(
      size_t batchLength,
      const gsl::span<const std::byte>& batchTableJsonData,
      const gsl::span<const std::byte>& batchTableBinaryData);

private:
  BatchTableMetadata(
      std::map<std::string, std::unique_ptr<PropertyView>> properties);

  std::map<std::string, std::unique_ptr<PropertyView>> _properties;
};
}