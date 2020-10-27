#pragma once

#include <Tile.h>
using Game::Prefabs::Tiles::Tile;

#include <ColliderComponent.h>
using Engine::Components::ColliderComponent;

namespace Game
{
	namespace Prefabs
	{
		namespace Tiles
		{
			//TODO: Make IDestroyableTile Interface?
			
			class PowerTile final : public Tile
			{
			public:
				PowerTile();

				ColliderComponent* GetCollider() const
				{
					return collider_;
				}

				

			private:
				ColliderComponent* collider_;

                        //List<Pickup>;

				void Hit()
				{
					//TODO: Only Check on when the player is in the air. (events plz.)
					
                              //TODO: Damage actors above brick.
					//TODO: Spawn Pickup if there is one.

					//TODO: Remove Pickup from list.
					
                                    

                                    if (spawn)
                                    {
							// Spawn what's in the container 
                                          //Instantiate(spawn, transform.position, Quaternion.identity);
                                          if (multiCoinBrick)
                                          {
                                                if (!_timerIsRunning) StartCoroutine(MultiCoinTimer()); //Only trigger once
                                          }
                                          else
                                          {
                                              // Stop animations like question block flash
                                                if (_sprite.GetComponent<Animator>()) _sprite.GetComponent<Animator>().enabled = false;
                                                _sprite.GetComponent<SpriteRenderer>().sprite = emptySprite;
                                                _empty = true; // Won't move on future hits
                                          }
                                    }
                                    else
                                    {
                                          if (other.GetComponent<PlayerMovementController>().MarioState == MarioState.Big)
                                          {
                                                SoundGuy.Instance.PlaySound("smb_breakblock");
                                                Instantiate(brickBrokenPrefab, transform.position, Quaternion.identity);
                                                Destroy(gameObject);
                                          }
                                    }
                              }
				}
			};
		}
	}
}

