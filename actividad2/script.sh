#!/bin/bash
echo "Indique User Git"
read GITHUB_USER
echo "Usuario: $GITHUB_USER" 
url1="https://api.github.com/users/"
url2=$url1$GITHUB_USER
curl -o infogit.json url2


