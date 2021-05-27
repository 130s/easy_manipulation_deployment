// Copyright 2020 Advanced Remanufacturing and Technology Centre
// Copyright 2020 ROS-Industrial Consortium Asia Pacific Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GRASP_PLANNER__END_EFFECTORS__END_EFFECTOR_HPP_
#define GRASP_PLANNER__END_EFFECTORS__END_EFFECTOR_HPP_

// For Visualization
#include <pcl/visualization/cloud_viewer.h>

// General Libraries
#include <memory>
#include <string>
#include <vector>
#include <cassert>

#include "grasp_planner/common/fcl_types.hpp"
#include "grasp_planner/grasp_object.hpp"

#include "visualization_msgs/msg/marker_array.hpp"

#define UNUSED(expr) do {(void)(expr);} while (0)

/*! \brief Generic class for an end effector, to be inherited by other end effectors*/
class EndEffector
{
public:
  using CollisionObject = grasp_planner::collision::CollisionObject;

  virtual void planGrasps(
    std::shared_ptr<GraspObject> object,
    emd_msgs::msg::GraspMethod * grasp_method,
    std::shared_ptr<CollisionObject> world_collision_object)
  {
    UNUSED(object);
    UNUSED(grasp_method);
    UNUSED(world_collision_object);
  }
  virtual void visualizeGrasps(pcl::visualization::PCLVisualizer::Ptr viewer) {UNUSED(viewer);}

  virtual visualization_msgs::msg::MarkerArray publishGraspsMarker(
    [[maybe_unused]] std::string camera_frame) {return markerArray;}

  virtual std::string getID() {return id;}

protected:
  std::string id;
  visualization_msgs::msg::MarkerArray markerArray;

};
#endif  // GRASP_PLANNER__END_EFFECTORS__END_EFFECTOR_HPP_
