; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt < %s -instcombine -S | FileCheck %s

declare double    @llvm.cos.f64(double %Val)
declare float     @llvm.cos.f32(float %Val)
declare <2 x float> @llvm.cos.v2f32(<2 x float> %Val)

declare float @llvm.fabs.f32(float %Val)
declare <2 x float> @llvm.fabs.v2f32(<2 x float> %Val)

define double @undef_arg() {
; CHECK-LABEL: @undef_arg(
; CHECK-NEXT:    ret double 0.000000e+00
;
  %r = call double @llvm.cos.f64(double undef)
  ret double %r
}

define float @undef_arg2(float %d) {
; CHECK-LABEL: @undef_arg2(
; CHECK-NEXT:    [[COSVAL:%.*]] = call float @llvm.cos.f32(float [[D:%.*]])
; CHECK-NEXT:    [[FSUM:%.*]] = fadd float [[COSVAL]], 0.000000e+00
; CHECK-NEXT:    ret float [[FSUM]]
;
  %cosval   = call float @llvm.cos.f32(float %d)
  %cosval2  = call float @llvm.cos.f32(float undef)
  %fsum   = fadd float %cosval2, %cosval
  ret float %fsum
}

define float @fneg_f32(float %x) {
; CHECK-LABEL: @fneg_f32(
; CHECK-NEXT:    [[COS:%.*]] = call float @llvm.cos.f32(float [[X:%.*]])
; CHECK-NEXT:    ret float [[COS]]
;
  %x.fneg = fsub float -0.0, %x
  %cos = call float @llvm.cos.f32(float %x.fneg)
  ret float %cos
}

define <2 x float> @fneg_v2f32(<2 x float> %x) {
; CHECK-LABEL: @fneg_v2f32(
; CHECK-NEXT:    [[COS:%.*]] = call <2 x float> @llvm.cos.v2f32(<2 x float> [[X:%.*]])
; CHECK-NEXT:    ret <2 x float> [[COS]]
;
  %x.fneg = fsub <2 x float> <float -0.0, float -0.0>, %x
  %cos = call <2 x float> @llvm.cos.v2f32(<2 x float> %x.fneg)
  ret <2 x float> %cos
}

define float @fabs_f32(float %x) {
; CHECK-LABEL: @fabs_f32(
; CHECK-NEXT:    [[COS:%.*]] = call float @llvm.cos.f32(float [[X:%.*]])
; CHECK-NEXT:    ret float [[COS]]
;
  %x.fabs = call float @llvm.fabs.f32(float %x)
  %cos = call float @llvm.cos.f32(float %x.fabs)
  ret float %cos
}

define float @fabs_fneg_f32(float %x) {
; CHECK-LABEL: @fabs_fneg_f32(
; CHECK-NEXT:    [[COS:%.*]] = call float @llvm.cos.f32(float [[X:%.*]])
; CHECK-NEXT:    ret float [[COS]]
;
  %x.fabs = call float @llvm.fabs.f32(float %x)
  %x.fabs.fneg = fsub float -0.0, %x.fabs
  %cos = call float @llvm.cos.f32(float %x.fabs.fneg)
  ret float %cos
}

define <2 x float> @fabs_fneg_v2f32(<2 x float> %x) {
; CHECK-LABEL: @fabs_fneg_v2f32(
; CHECK-NEXT:    [[COS:%.*]] = call <2 x float> @llvm.cos.v2f32(<2 x float> [[X:%.*]])
; CHECK-NEXT:    ret <2 x float> [[COS]]
;
  %x.fabs = call <2 x float> @llvm.fabs.v2f32(<2 x float> %x)
  %x.fabs.fneg = fsub <2 x float> <float -0.0, float -0.0>, %x.fabs
  %cos = call <2 x float> @llvm.cos.v2f32(<2 x float> %x.fabs.fneg)
  ret <2 x float> %cos
}
