/************************************************************************************

Filename    :   OVR_Skeleton.cpp
Content     :   skeleton for arm model implementation
Created     :   2/20/2017
Authors     :   Jonathan E. Wright

Copyright   :   Copyright (c) Facebook Technologies, LLC and its affiliates. All rights reserved.

************************************************************************************/

#include "OVR_Skeleton.h"
#include "OVR_Types.h"
using OVR::Posef;

namespace OVRFW {

ovrSkeleton::ovrSkeleton() {}

const ovrJoint& ovrSkeleton::GetJoint(int const idx) const {
    OVR_ASSERT(idx >= 0 && idx < static_cast<int>(Joints.size()));
    return Joints[idx];
}

int ovrSkeleton::GetParentIndex(int const idx) const {
    if (idx < 0 || idx >= static_cast<int>(Joints.size())) {
        return -1;
    }
    return Joints[idx].ParentIndex;
}

void ovrSkeleton::Transform(const Posef& transformPose, const Posef& inPose, Posef& outPose) {
    outPose.Translation = transformPose.Translation + (transformPose.Rotation * inPose.Translation);
    outPose.Rotation = transformPose.Rotation * inPose.Rotation;
}

void ovrSkeleton::TransformByParent(
    const Posef& parentPose,
    const int jointIndex,
    const Posef& inPose,
    const std::vector<ovrJointMod>& jointMods,
    Posef& outPose) {
    OVR_ASSERT(&inPose != &outPose);

    bool appliedJointMod = false;
    for (int i = 0; i < static_cast<int>(jointMods.size()); ++i) {
        const ovrJointMod& mod = jointMods[i];
        if (mod.Type == ovrJointMod::MOD_LOCAL && mod.JointIndex == jointIndex) {
            Transform(mod.Pose, inPose, outPose);
            appliedJointMod = true;
        }
    }

    if (appliedJointMod) {
        Transform(parentPose, outPose, outPose);
    } else {
        Transform(parentPose, inPose, outPose);
    }

    for (int i = 0; i < static_cast<int>(jointMods.size()); ++i) {
        const ovrJointMod& mod = jointMods[i];
        if (mod.Type == ovrJointMod::MOD_WORLD && mod.JointIndex == jointIndex) {
            outPose.Rotation = mod.Pose.Rotation;
        }
    }
}

void ovrSkeleton::Transform(
    const Posef& worldPose,
    const std::vector<ovrJoint>& inJoints,
    const std::vector<ovrJointMod>& jointMods,
    std::vector<ovrJoint>& outJoints) {
    if (outJoints.size() != inJoints.size()) {
        OVR_ASSERT(outJoints.size() == inJoints.size());
        return;
    }

    TransformByParent(worldPose, 0, inJoints[0].Pose, jointMods, outJoints[0].Pose);

    for (int i = 1; i < static_cast<int>(inJoints.size()); ++i) {
        const ovrJoint& inJoint = inJoints[i];
        const ovrJoint& parentJoint = outJoints[inJoint.ParentIndex];
        ovrJoint& outJoint = outJoints[i];
        TransformByParent(parentJoint.Pose, i, inJoint.Pose, jointMods, outJoint.Pose);
    }
}

void ovrSkeleton::ApplyJointMods(
    const std::vector<ovrJointMod>& jointMods,
    std::vector<ovrJoint>& joints) {
    for (int i = 0; i < static_cast<int>(jointMods.size()); ++i) {
        const ovrJointMod& mod = jointMods[i];
        if (mod.Type == ovrJointMod::MOD_WORLD) {
            ovrJoint& joint = joints[mod.JointIndex];
            Transform(mod.Pose, joint.Pose, joint.Pose);
        }
    }
}

} // namespace OVRFW
