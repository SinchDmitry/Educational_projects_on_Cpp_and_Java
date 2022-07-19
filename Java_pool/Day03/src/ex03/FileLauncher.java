package ex03;

import java.io.IOException;
import java.io.InputStream;
import java.net.MalformedURLException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

public class FileLauncher extends Thread {
    private int                     _numThreads;
    private List<FileThread>        _workList;
    private BlockingQueue<FileInfo> _queue;

    private static class FileInfo {
        private final String _url;
        private final int _numOfFile;

        public FileInfo(String url, int num) {
            _url = url;
            _numOfFile = num;
        }

        @Override
        public String toString() {
            return String.format("%d - %s\n", _numOfFile, _url);
        }
    }

    private static class FileThread extends Thread {
        private final BlockingQueue<FileInfo> _workQueue;

        public FileThread(BlockingQueue<FileInfo> queue) {
            _workQueue = queue;
        }

        @Override
        public void run() {
            while (true) {
                synchronized (this._workQueue) {
                    if (this._workQueue.isEmpty()) {
                        return;
                    }
                }
                FileInfo info = null;
                try {
                    info = this._workQueue.take();
                    System.out.printf("%s start download file number %d\n", this.getName(), info._numOfFile);
                    String fileName = info._url.substring(info._url.lastIndexOf('/') + 1);
                    URL dlUrl = new URL(info._url);
                    InputStream urlStream = dlUrl.openStream();
                    Files.copy(urlStream, Paths.get(fileName), StandardCopyOption.REPLACE_EXISTING);
                    System.out.printf("%s finish download file number %d\n", this.getName(), info._numOfFile);
                } catch (InterruptedException e) {
                    System.err.printf("Error : %s caught InterruptedException\n", this.getName());
                } catch (MalformedURLException e) {
                    System.err.printf("Error : %s file %d URL is malformed\n", this.getName(), info._numOfFile);
                } catch (IOException e) {
                    System.err.printf("Error : %s download file %d failed: %s\n", this.getName(), info._numOfFile, e.getMessage());
                }
            }
        }
    }

    public FileLauncher(int numOfThread, Map<Integer, String> fileData) {
        if (numOfThread > 0) {
            _numThreads = numOfThread;
            _queue = new LinkedBlockingQueue<>();
            _workList = new ArrayList<>();
            for (int i = 1; i <= fileData.size(); ++i) {
                try {
                    FileInfo tmpData = new FileInfo(fileData.get(i), i);
                    _queue.put(tmpData);
                } catch (InterruptedException e) {
                    System.err.println(e.getMessage());
                }
            }
            for (int i = 0; i < _numThreads; ++i) {
                FileThread tmp = new FileThread(_queue);
                _workList.add(tmp);
            }
            System.out.println(_workList);
        } else {
            System.out.println("Error : wrong number of threads");
        }
    }

    public void generalAction() {
        for (FileThread i : _workList ) {
            i.start();
        }
        for (FileThread i : _workList ) {
            try {
                i.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
