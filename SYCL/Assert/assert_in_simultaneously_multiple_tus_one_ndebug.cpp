// FIXME unsuppoerted on CUDA until fallback libdevice becomes available
// UNSUPPORTED: cuda
// FIXME disable the test on Linux on OpenCL on FPGA as there's some funny
// failure taking place in this configuration on CI. The test should be enabled
// with this configuration once it's debugged.
// UNSUPPORTED: linux && opencl && fpga
// RUN: %clangxx -fsycl -fsycl-targets=%sycl_triple -DDEFINE_NDEBUG_INFILE2 -I %S/Inputs %S/assert_in_simultaneously_multiple_tus.cpp %S/Inputs/kernels_in_file2.cpp -o %t.out %threads_lib
// RUN: %CPU_RUN_PLACEHOLDER %t.out &> %t.txt || true
// RUN: %CPU_RUN_PLACEHOLDER FileCheck %s --input-file %t.txt
// RUN: %GPU_RUN_PLACEHOLDER %t.out &> %t.txt || true
// RUN: %GPU_RUN_PLACEHOLDER FileCheck %s --input-file %t.txt
// RUN: %ACC_RUN_PLACEHOLDER %t.out &> %t.txt || true
// RUN: %ACC_RUN_PLACEHOLDER FileCheck %s --input-file %t.txt
//
// CHECK:      this message from file1
// CHECK-NOT:  this message from file2
// CHECK-NOT:  The test ended.