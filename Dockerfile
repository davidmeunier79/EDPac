# Generated by: Neurodocker version 0.7.0+15.ga4940e3.dirty
# Latest release: Neurodocker version 0.7.0
#
# Thank you for using Neurodocker. If you discover any issues
# or ways to improve this software, please submit an issue or
# pull request on our GitHub repository:
#
#     https://github.com/ReproNim/neurodocker
#
# Timestamp: 2020/12/02 18:33:44 UTC

FROM ubuntu:14.04

USER root

ARG DEBIAN_FRONTEND="noninteractive"

MAINTAINER David Meunier "david.meunier@univ-amu.fr"

RUN apt-get update -qq

RUN apt-get update && apt-get install -y git

######################## packages

RUN apt-get install -y xorg openbox

RUN apt-get install -y gcc build-essential

RUN apt-get install -y mpich

RUN apt-get install -y libx11-dev libxpm-dev libxft-dev libxext-dev mesa-common-dev

RUN apt-get install -y  linux-generic libmpich-dev libopenmpi-dev lam4-dev

############################################# install macapype from github
RUN mkdir -p /opt/packages/

ADD https://api.github.com/repos/davidmeunier79/EDPac/git/refs/heads/main version.json
WORKDIR /opt/packages/

RUN git clone https://github.com/davidmeunier79/EDPac.git
WORKDIR /opt/packages/EDPac


######################## Testing


RUN ls -l

RUN make runEvo

