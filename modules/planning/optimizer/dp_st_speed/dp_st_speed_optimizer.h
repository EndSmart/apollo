/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file dp_st_speed_optimizer.h
 **/

#ifndef MODULES_PLANNING_OPTIMIZER_DP_ST_SPEED_OPTIMIZER_H_
#define MODULES_PLANNING_OPTIMIZER_DP_ST_SPEED_OPTIMIZER_H_

#include <string>

#include "modules/planning/proto/dp_st_speed_config.pb.h"
#include "modules/planning/proto/st_boundary_config.pb.h"

#include "modules/planning/optimizer/speed_optimizer.h"
#include "modules/planning/optimizer/st_graph/st_boundary_mapper_impl.h"

namespace apollo {
namespace planning {

class DpStSpeedOptimizer : public SpeedOptimizer {
 public:
  explicit DpStSpeedOptimizer(const std::string& name);

  bool Init() override;

 private:
  apollo::common::Status Process(const PathData& path_data,
                                 const TrajectoryPoint& init_point,
                                 const ReferenceLine& reference_line,
                                 DecisionData* const decision_data,
                                 SpeedData* const speed_data) override;
  StBoundaryMapperImpl boundary_mapper_;
  DpStSpeedConfig dp_st_speed_config_;
};

}  // namespace planning
}  // namespace apollo

#endif  // MODULES_PLANNING_OPTIMIZER_DP_ST_SPEED_OPTIMIZER_H_
