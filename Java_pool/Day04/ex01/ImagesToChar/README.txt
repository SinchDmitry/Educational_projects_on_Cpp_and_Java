rm -rf target
mkdir target
javac -d target src/java/edu/school21/printer/*/*.java
cp -R src/resources target/.
jar cfm target/images-to-chars-printer.jar src/manifest.txt -C target .
chmod 777 target/images-to-chars-printer.jar
#java -classpath ./target edu.school21.printer.app.Program
java -jar target/images-to-chars-printer.jar 0 .
