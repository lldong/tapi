//===- tapi/Core/TextStub_v3.h - Text Stub v3 -------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Defines the content of a text stub v3 file.
///
//===----------------------------------------------------------------------===//

#ifndef TAPI_CORE_TEXT_STUB_V3_H
#define TAPI_CORE_TEXT_STUB_V3_H

#include "tapi/Core/File.h"
#include "tapi/Core/LLVM.h"
#include "tapi/Core/Registry.h"
#include "tapi/Core/YAMLReaderWriter.h"
#include "tapi/Defines.h"

namespace llvm {
namespace yaml {
class IO;
} // namespace yaml
} // namespace llvm

TAPI_NAMESPACE_INTERNAL_BEGIN

namespace stub {
namespace v3 {

class YAMLDocumentHandler : public DocumentHandler {
  bool canRead(MemoryBufferRef memBufferRef,
               FileType types = FileType::All) const override;
  FileType getFileType(MemoryBufferRef memBufferRef) const override;
  bool canWrite(const File *file) const override;
  bool handleDocument(llvm::yaml::IO &io, const File *&file) const override;
};

} // end namespace v3.
} // end namespace stub.

TAPI_NAMESPACE_INTERNAL_END

#endif // TAPI_CORE_TEXT_STUB_V3_H
