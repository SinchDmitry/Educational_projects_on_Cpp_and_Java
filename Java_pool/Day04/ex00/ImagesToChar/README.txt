rm -rf target
mkdir target
javac -d target src/java/edu/school21/printer/*/*.java
java -classpath ./target edu.school21.printer.app.Program \
/Users/aarchiba/Desktop/Educational_projects_on_Cpp_and_Java/Java_pool/Day04/ex00/ImagesToChar/src/java/edu/school21/printer/image.bmp \
0 .