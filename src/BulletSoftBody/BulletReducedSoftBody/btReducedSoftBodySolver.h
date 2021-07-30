#ifndef BT_REDUCED_SOFT_BODY_SOLVER_H
#define BT_REDUCED_SOFT_BODY_SOLVER_H

#include "btReducedSoftBody.h"
#include "../btDeformableBodySolver.h"

class btReducedSoftBody;

class btReducedSoftBodySolver : public btDeformableBodySolver
{
 protected:
  btScalar m_dampingAlpha;
  btScalar m_dampingBeta;

  btVector3 m_gravity;

  void predictReduceDeformableMotion(btScalar solverdt);

  void applyExplicitForce(btScalar solverdt);

 public:
  btReducedSoftBodySolver();
  ~btReducedSoftBodySolver() {}

  void setDamping(btScalar alpha, btScalar beta);

  void setGravity(const btVector3& gravity);

  virtual SolverTypes getSolverType() const
  {
    return REDUCED_DEFORMABLE_SOLVER;
  }

  virtual void predictMotion(btScalar solverdt);

  virtual void applyTransforms(btScalar timeStep);

  virtual void solveConstraints(btScalar timeStep);

  // virtual void setProjection() {}

  // virtual void setLagrangeMultiplier() {}

  // virtual void setupDeformableSolve(bool implicit);

  // virtual void solveDeformableConstraints(btScalar solverdt);
};

#endif // BT_REDUCED_SOFT_BODY_DYNAMICS_WORLD_H