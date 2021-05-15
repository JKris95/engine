// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <Metal/Metal.h>

#include <memory>

#include "flutter/fml/macros.h"

namespace impeller {

class ShaderLibrary;

class Context {
 public:
  Context(std::string shaders_directory);

  ~Context();

  bool IsValid() const;

  id<MTLCommandQueue> GetRenderQueue() const;

  id<MTLCommandQueue> GetTransferQueue() const;

  std::shared_ptr<ShaderLibrary> GetShaderLibrary() const;

 private:
  id<MTLDevice> device_ = nullptr;
  id<MTLCommandQueue> render_queue_ = nullptr;
  id<MTLCommandQueue> transfer_queue_ = nullptr;
  std::shared_ptr<ShaderLibrary> shader_library_;
  bool is_valid_ = false;

  FML_DISALLOW_COPY_AND_ASSIGN(Context);
};

}  // namespace impeller