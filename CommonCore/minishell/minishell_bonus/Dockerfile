# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 15:40:43 by dcsicsak          #+#    #+#              #
#    Updated: 2025/02/16 15:40:51 by dcsicsak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Use Ubuntu as the base image
FROM ubuntu:latest

# Set the working directory inside the container
WORKDIR /app

# Install dependencies required for Minishell
RUN apt update && apt install -y make gcc libreadline-dev

# Copy the project files into the container
COPY . .

# Build Minishell inside the container
RUN make

# Define the command that starts the shell
CMD ["./minishell"]

