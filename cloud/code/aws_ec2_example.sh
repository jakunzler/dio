# This script demonstrates how to use AWS CLI commands to manage EC2 instances and security groups.
# The script includes commands to describe instances, describe security groups, create a security group, authorize ingress rules, and run an instance.
# Ensure you have AWS CLI installed and configured with appropriate permissions.

# CreateSecurityGroup
aws ec2 create-security-group --group-name "launch-wizard-1" --description "launch-wizard-1 created 2025-04-03T14:22:21.564Z" --vpc-id "vpc-0b1654353b9f1b7b5" 

# AuthorizeSecurityGroupIngress
aws ec2 authorize-security-group-ingress --group-id "sg-preview-1" --ip-permissions '{"IpProtocol":"tcp","FromPort":22,"ToPort":22,"IpRanges":[{"CidrIp":"0.0.0.0/0"}]}' 

# RunInstances
aws ec2 run-instances --image-id "ami-092cd6a84ad570057" --instance-type "t2.micro" --network-interfaces '{"AssociatePublicIpAddress":true,"DeviceIndex":0,"Groups":["sg-preview-1"]}' --credit-specification '{"CpuCredits":"standard"}' --metadata-options '{"HttpEndpoint":"enabled","HttpPutResponseHopLimit":2,"HttpTokens":"required"}' --private-dns-name-options '{"HostnameType":"ip-name","EnableResourceNameDnsARecord":true,"EnableResourceNameDnsAAAARecord":false}' --count "1" 