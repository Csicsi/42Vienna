# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalajqi <lalajqi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 21:56:14 by lalajqi           #+#    #+#              #
#    Updated: 2024/03/03 23:06:11 by lalajqi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for the dictionary project

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Source files and dependencies
SRCS_DIR = srcs
INCLUDES_DIR = includes
DEPENDENCIES_DIR = dicts

# Source files, header files, and dependencies
SRCS = $(wildcard $(SRCS_DIR)/*.c)
INCLUDES = -I$(INCLUDES_DIR)
DEPENDENCIES = $(wildcard $(DICTS_DIR)/*.dict)

# Executable name
TARGET = rush-02

# Build rules
all: create_dirs $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(DEPENDENCIES)
	
create_dirs:
	mkdir -p $(SRCS_DIR) $(INCLUDES_DIR) $(DICTS_DIR)

# Clean rule
clean:
	rm -f $(TARGET)

.PHONY: all clean

