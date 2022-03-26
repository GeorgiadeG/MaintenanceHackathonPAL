raspivid -o $1.h264 -t $2
git add .
git commit -m "add video"
git push

