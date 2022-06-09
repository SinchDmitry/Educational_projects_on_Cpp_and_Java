import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

class sigInfo{
	private String	name;
	private	int[]	val;
	
	public sigInfo(String	name, int[]	val) {
		this.name = name;
		this.val = val;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setVal(int[] val) {
		this.val = val;
	}

	public String getName() {
		return this.name;
	}

	public int[] getVal() {
		return this.val;
	}
}

public class SignatureChecker {
	private FileOutputStream	result;
	// private sigInfo				sigData;
	private List<sigInfo>		sigList;	
	// private Map<String, int[]>	signatureMap;

	public SignatureChecker() {
		this.result = null;
		this.sigList = new LinkedList<>(); 
		// this.signatureMap = new HashMap<>();
	}

	public boolean init() {
        if (!signParser()) {
            return false;
        }
        try {
            this.result = new FileOutputStream("result.txt");
        } catch (IOException e) {
            System.err.println(e.getMessage());
            return false;
        }
        return true;
    }

	public boolean signParser() {
		String	str = "";
		int		ch;

		try (FileInputStream sign = new FileInputStream("signatures.txt")) {
			while ((ch = sign.read()) != -1) {
				if (ch == '\n') {
					if (!checkFormat(str))
                         return false;
					str = "";
				}
				str += (char)ch;
			}
		} catch (FileNotFoundException e) {
            System.err.println("signatures.txt not found");
            return false;
        } catch (IOException e) {
            System.err.println(e.getMessage());
            return false;
        } catch (NumberFormatException e) {
            System.err.printf("Parse error: %s\n", e.getMessage());
            return false;
        }
		return true;
	}

	public boolean checkFormat(String str) {
		String tmp[]= str.split(",");
 
		if (tmp.length != 2) {
			System.err.println("Bad signatures.txt");
            return false;
        }
		
		String[] bytes = tmp[1].trim().split("\\s+");
		int len = bytes.length;
        if (len == 0) {
			System.err.printf("%s signature is empty\n", tmp[0]);
            return false;
        }
		
		int[] sig = new int[len];
        for (int i = 0; i < len; ++i) {
			sig[i] = Integer.parseInt(bytes[i], 16);
        }
		
		sigInfo nowInfo = new sigInfo(tmp[0], sig);
        this.sigList.add(nowInfo);

		return true;
	}

	public void checkFileSignature(String path) {
		List<Integer> byteLst = new LinkedList<>();

		try (FileInputStream checkFile = new FileInputStream(path)) {
            int c;
            while ((c = checkFile.read()) != -1) {
                byteLst.add(c);

				
			} 
		} catch (Exception e) {

		}

	}

}
