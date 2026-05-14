# Example Makefile for foundation/libft module integration.

ROOT := ../..
MODULE_NAME := libft
SRC_DIR := src
INCLUDE_DIR := include
TEST_DIR := tests

include $(ROOT)/ecosystem/build-system/module.mk
