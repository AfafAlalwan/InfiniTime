#include "components/rf/StandardIfTree.h"

using namespace Pinetime::Controllers;

unsigned int StandardIfTree::StandardIfTree_predict(float const pX[8]) {
	unsigned int predCnt[2] = {0,0};
	predCnt[StandardIfTree_predict0(pX)]++;
	unsigned int pred = 0;
	unsigned int cnt = predCnt[0];
	for (unsigned int i = 1; i < 2; ++i) {
		if (predCnt[i] > cnt) {
				cnt = predCnt[i];
				pred = i;
			}
		}
	return pred;				
}

unsigned int StandardIfTree::StandardIfTree_predict0(float const pX[8]){
	if(pX[5] <= 28.84999942779541){
		if(pX[1] <= 160.0){
			if(pX[7] <= 42.0){
				if(pX[1] <= 153.0){
					if(pX[1] <= 114.5){
						return 0;
					} else {
						if(pX[7] <= 28.0){
							return 0;
						} else {
							if(pX[5] <= 12.0){
								return 1;
							} else {
								if(pX[2] <= 73.0){
									if(pX[3] <= 11.5){
										if(pX[2] <= 70.0){
											return 0;
										} else {
											return 1;
										}
									} else {
										return 0;
									}
								} else {
									return 0;
								}
							}
						}
					}
				} else {
					if(pX[2] <= 73.0){
						return 0;
					} else {
						return 1;
					}
				}
			} else {
				if(pX[5] <= 9.800000190734863){
					if(pX[6] <= 0.4359999895095825){
						return 1;
					} else {
						return 0;
					}
				} else {
					if(pX[3] <= 25.5){
						if(pX[3] <= 23.0){
							if(pX[1] <= 105.5){
								if(pX[0] <= 2.5){
									return 1;
								} else {
									if(pX[7] <= 46.0){
										return 1;
									} else {
										return 0;
									}
								}
							} else {
								if(pX[0] <= 5.0){
									if(pX[5] <= 21.699999809265137){
										return 0;
									} else {
										return 1;
									}
								} else {
									return 0;
								}
							}
						} else {
							return 1;
						}
					} else {
						return 0;
					}
				}
			}
		} else {
			if(pX[1] <= 188.5){
				return 1;
			} else {
				return 0;
			}
		}
	} else {
		if(pX[1] <= 127.5){
			if(pX[6] <= 0.8060000240802765){
				if(pX[2] <= 89.0){
					if(pX[0] <= 1.5){
						if(pX[5] <= 35.29999923706055){
							if(pX[2] <= 87.0){
								if(pX[7] <= 28.5){
									if(pX[2] <= 29.0){
										return 1;
									} else {
										if(pX[6] <= 0.2814999967813492){
											if(pX[4] <= 45.0){
												if(pX[2] <= 81.0){
													return 1;
												} else {
													return 0;
												}
											} else {
												return 0;
											}
										} else {
											if(pX[5] <= 33.39999961853027){
												return 0;
											} else {
												if(pX[5] <= 33.69999885559082){
													return 1;
												} else {
													return 0;
												}
											}
										}
									}
								} else {
									if(pX[5] <= 33.29999923706055){
										return 0;
									} else {
										return 1;
									}
								}
							} else {
								return 1;
							}
						} else {
							if(pX[4] <= 59.5){
								if(pX[3] <= 26.0){
									if(pX[2] <= 75.0){
										return 1;
									} else {
										if(pX[6] <= 0.2224999964237213){
											return 0;
										} else {
											if(pX[1] <= 101.0){
												return 1;
											} else {
												return 0;
											}
										}
									}
								} else {
									return 0;
								}
							} else {
								return 0;
							}
						}
					} else {
						if(pX[7] <= 24.5){
							return 0;
						} else {
							if(pX[1] <= 106.5){
								if(pX[1] <= 99.5){
									return 0;
								} else {
									if(pX[6] <= 0.5305000096559525){
										return 0;
									} else {
										return 1;
									}
								}
							} else {
								if(pX[7] <= 25.5){
									return 1;
								} else {
									if(pX[7] <= 46.5){
										if(pX[5] <= 34.60000038146973){
											if(pX[4] <= 175.5){
												if(pX[6] <= 0.4684999883174896){
													if(pX[2] <= 71.0){
														if(pX[7] <= 28.0){
															return 0;
														} else {
															if(pX[1] <= 119.5){
																return 1;
															} else {
																if(pX[0] <= 7.0){
																	return 1;
																} else {
																	return 0;
																}
															}
														}
													} else {
														return 1;
													}
												} else {
													return 0;
												}
											} else {
												return 0;
											}
										} else {
											return 0;
										}
									} else {
										return 0;
									}
								}
							}
						}
					}
				} else {
					if(pX[7] <= 44.5){
						return 1;
					} else {
						return 0;
					}
				}
			} else {
				if(pX[5] <= 46.19999885559082){
					if(pX[6] <= 1.3949999809265137){
						if(pX[2] <= 69.0){
							if(pX[1] <= 93.0){
								return 0;
							} else {
								if(pX[2] <= 67.0){
									return 1;
								} else {
									return 0;
								}
							}
						} else {
							return 1;
						}
					} else {
						return 0;
					}
				} else {
					return 0;
				}
			}
		} else {
			if(pX[1] <= 154.5){
				if(pX[2] <= 48.0){
					return 1;
				} else {
					if(pX[4] <= 327.5){
						if(pX[2] <= 64.5){
							return 0;
						} else {
							if(pX[6] <= 0.24500000476837158){
								if(pX[3] <= 7.5){
									if(pX[1] <= 140.5){
										return 0;
									} else {
										return 1;
									}
								} else {
									return 0;
								}
							} else {
								if(pX[2] <= 73.0){
									if(pX[2] <= 67.0){
										if(pX[0] <= 1.5){
											return 1;
										} else {
											return 0;
										}
									} else {
										if(pX[1] <= 152.5){
											return 1;
										} else {
											return 0;
										}
									}
								} else {
									if(pX[2] <= 77.0){
										if(pX[5] <= 38.80000114440918){
											if(pX[3] <= 13.0){
												return 0;
											} else {
												if(pX[3] <= 30.5){
													return 1;
												} else {
													return 0;
												}
											}
										} else {
											return 1;
										}
									} else {
										if(pX[6] <= 0.984499990940094){
											if(pX[7] <= 40.5){
												if(pX[2] <= 83.0){
													if(pX[6] <= 0.75){
														return 0;
													} else {
														return 1;
													}
												} else {
													if(pX[6] <= 0.30650000274181366){
														if(pX[5] <= 33.70000076293945){
															return 0;
														} else {
															if(pX[6] <= 0.2850000113248825){
																return 0;
															} else {
																return 1;
															}
														}
													} else {
														if(pX[1] <= 149.0){
															if(pX[3] <= 50.0){
																return 1;
															} else {
																return 0;
															}
														} else {
															return 1;
														}
													}
												}
											} else {
												return 1;
											}
										} else {
											if(pX[2] <= 80.0){
												return 1;
											} else {
												return 0;
											}
										}
									}
								}
							}
						}
					} else {
						return 0;
					}
				}
			} else {
				if(pX[2] <= 93.0){
					if(pX[5] <= 46.80000114440918){
						if(pX[2] <= 75.0){
							if(pX[6] <= 0.3075000047683716){
								if(pX[6] <= 0.2695000022649765){
									if(pX[5] <= 39.05000114440918){
										if(pX[4] <= 62.5){
											if(pX[6] <= 0.16750000417232513){
												return 1;
											} else {
												return 0;
											}
										} else {
											return 1;
										}
									} else {
										return 0;
									}
								} else {
									return 0;
								}
							} else {
								if(pX[7] <= 48.0){
									return 1;
								} else {
									if(pX[7] <= 54.0){
										return 0;
									} else {
										return 1;
									}
								}
							}
						} else {
							return 1;
						}
					} else {
						if(pX[2] <= 75.5){
							return 1;
						} else {
							if(pX[3] <= 53.0){
								return 0;
							} else {
								return 1;
							}
						}
					}
				} else {
					return 0;
				}
			}
		}
	}
}
