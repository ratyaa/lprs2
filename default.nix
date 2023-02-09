{ pkgs ? import <nixpkgs> {} }:

let
  cppPackages = [
    pkgs.clang
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
  ];
}
