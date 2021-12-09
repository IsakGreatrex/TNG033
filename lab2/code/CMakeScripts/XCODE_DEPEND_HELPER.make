# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.Exercise1.Debug:
/Users/isakgreatrex/Desktop/TNG033-labs/lab2\ 2/code/Debug/Exercise1:
	/bin/rm -f /Users/isakgreatrex/Desktop/TNG033-labs/lab2\ 2/code/Debug/Exercise1


PostBuild.Exercise1.Release:
/Users/isakgreatrex/Desktop/TNG033-labs/lab2\ 2/code/Release/Exercise1:
	/bin/rm -f /Users/isakgreatrex/Desktop/TNG033-labs/lab2\ 2/code/Release/Exercise1


PostBuild.Exercise1.MinSizeRel:
/Users/isakgreatrex/Desktop/TNG033-labs/lab2\ 2/code/MinSizeRel/Exercise1:
	/bin/rm -f /Users/isakgreatrex/Desktop/TNG033-labs/lab2\ 2/code/MinSizeRel/Exercise1


PostBuild.Exercise1.RelWithDebInfo:
/Users/isakgreatrex/Desktop/TNG033-labs/lab2\ 2/code/RelWithDebInfo/Exercise1:
	/bin/rm -f /Users/isakgreatrex/Desktop/TNG033-labs/lab2\ 2/code/RelWithDebInfo/Exercise1




# For each target create a dummy ruleso the target does not have to exist
