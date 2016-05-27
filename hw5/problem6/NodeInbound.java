package th.in.whs.ku;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.KeyValueTextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class NodeInbound {
    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf, "webapp7 node inbound");
        job.setInputFormatClass(KeyValueTextInputFormat.class);

        job.setJarByClass(NodeInbound.class);
        job.setMapperClass(NodeInboundMapper.class);
        job.setCombinerClass(NodeInboundReducer.class);
        job.setReducerClass(NodeInboundReducer.class);

        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(IntWritable.class);

        FileInputFormat.addInputPath(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));
        System.out.println("Max split " + FileInputFormat.getMaxSplitSize(job));
        System.out.println("Min split " + FileInputFormat.getMinSplitSize(job));

        System.exit(job.waitForCompletion(true) ? 0 : 1);
    }
}
