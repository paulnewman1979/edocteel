num=`pwd | sed 's/.*\///g'`

scp -i ~/.ssh/awstao.pem main.cpp ec2-user@ec2-52-11-137-68.us-west-2.compute.amazonaws.com:/home/ec2-user/git/github/edocteel/$num/
