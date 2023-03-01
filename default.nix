{ pkgs ? import <nixpkgs> {} }:

let
  cppPackages = [
    pkgs.clang_15
    pkgs.clang-tools_15
    pkgs.gcc
  ];
  cppTools = [
    pkgs.cmake
    pkgs.lldb
    pkgs.gdb
  ];
in
      
pkgs.mkShell {
  buildInputs = [
    cppPackages
    cppTools
    pkgs.gnuplot
  ];
}
