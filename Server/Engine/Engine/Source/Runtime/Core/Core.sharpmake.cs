using System;
using System.IO;
using Sharpmake;

[Generate]
public class Core : CommonProject
{
    public Core() { }

    public override void ConfigureAll(Configuration conf, EngineTarget target)
    {
        base.ConfigureAll(conf, target);
        conf.SolutionFolder = @"Engine/Source/Runtime";
    }
}