#include "proof.hpp"


Proof::Proof()
{
    this->target = 1;
    this->target << (256-TARGET_BITS);
}