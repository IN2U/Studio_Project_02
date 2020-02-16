# Studio_Project_02
If you are git 1337 h4xxor(meaning you use the terminal for git), then follow along, if you are using the gui version, then idk.

You can just download this as a zip or you can do

"git clone https://github.com/IN2U/Studio_Project_02.git" in your terminal

You should get Studio_Project_02 file, then click on it to view the child folders. That's where you should open your terminal again.

Basically, before you do any changes to the source code, make sure you make a branch first by doing 

"git checkout -b nameOfBranch" for me, nameOfBranch is usually the thing I will be doing like menuSystem

Once you are sure you are done,

"git add fileName or ./-a(to add all changes to staging area)"

"git commit -m 'what you did in one sentence'"

then since you are still at the branch

"git checkout master"

"git merge nameOfBranch"

"git pull origin master" to get latest updates from the remote repo before you push anything

"git push"

Let's do our best to not do any merge conflict by only changing what you are supposed to change, tell others if you need to make changes to their part.

I'm not a git pro so there might be some problems so it's still recommended to learn it yourself.
