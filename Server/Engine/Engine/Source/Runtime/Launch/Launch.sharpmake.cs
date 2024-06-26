using System;
using System.IO;
using Sharpmake;

[Generate]
public class Launch : CommonProject
{
    public Launch() { }

    public override void ConfigureAll(Configuration conf, EngineTarget target)
    {
        base.ConfigureAll(conf, target);
        conf.SolutionFolder = @"Engine/Source/Runtime";
        conf.AddPublicDependency<Core>(target);
        //conf.AddPublicDependency<Engine>(target);
        //conf.AddPublicDependency<EngineSettings>(target);
        //if (target.LaunchType == ELaunchType.Editor)
        //{
        //    conf.AddPublicDependency<EngineEd>(target);
        //}
    }
}