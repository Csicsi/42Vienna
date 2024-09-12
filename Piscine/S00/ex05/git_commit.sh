#!/bin/bash
cd "$(git rev-parse --show-toplevel)"
git log -n 5 --format="%H"
