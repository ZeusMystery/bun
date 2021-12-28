#!/bin/bash

echo "To get started, login to GitHub and clone Bun's GitHub repo into /workspaces/bun"
echo "Make sure to login with a Personal Access Token"
echo "# First time setup"
echo "gh auth login"
echo "gh repo clone Jarred-Sumner/bun . -- --depth=1 --progress -j8"
echo ""
echo "# Compile bun dependencies (zig is already compiled)"
echo "make devcontainer"
echo ""
echo "# Build Bun for development"
echo "make dev"
echo ""
echo "# Run bun"
echo "bun-debug"
